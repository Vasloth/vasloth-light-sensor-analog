#include "VaslothLightSensor.h"

VaslothLightSensor::VaslothLightSensor(uint8_t pin) {
  _pin = pin;
}

void VaslothLightSensor::begin() {
  pinMode(_pin, INPUT);
  analogSetAttenuation(ADC_11db);
  analogSetWidth(12);
}

// ---------- ADC filtrado ----------
uint16_t VaslothLightSensor::readADCProcessed() {
  uint16_t buffer[OVERSAMPLE_COUNT];

  for (int i = 0; i < OVERSAMPLE_COUNT; i++) {
    buffer[i] = analogRead(_pin);
    delayMicroseconds(200);
  }

  for (int i = 0; i < OVERSAMPLE_COUNT - 1; i++) {
    for (int j = i + 1; j < OVERSAMPLE_COUNT; j++) {
      if (buffer[j] < buffer[i]) {
        uint16_t t = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = t;
      }
    }
  }

  uint32_t sum = 0;
  int count = 0;
  for (int i = DISCARD_SAMPLES; i < OVERSAMPLE_COUNT - DISCARD_SAMPLES; i++) {
    sum += buffer[i];
    count++;
  }

  return sum / count;
}

// ---------- EMA ----------
uint16_t VaslothLightSensor::readRawFiltered() {
  uint16_t value = readADCProcessed();

  if (!_started) {
    _emaValue = value;
    _started = true;
  } else {
    _emaValue = EMA_ALPHA * value + (1.0f - EMA_ALPHA) * _emaValue;
  }

  return (uint16_t)_emaValue;
}

// ---------- Mapeo ----------
uint8_t VaslothLightSensor::mapLight(uint16_t value) {
  if (value < DEADZONE) return 0;

  value = constrain(value, _calibMin, _calibMax);
  return map(value, _calibMin, _calibMax, 0, 100);
}

uint8_t VaslothLightSensor::readPercent() {
  return mapLight(readRawFiltered());
}

// ---------- Serial ----------
void VaslothLightSensor::handleSerialCalibration() {
  if (!Serial.available()) return;

  String cmd = Serial.readStringUntil('\n');
  cmd.trim();
  cmd.toUpperCase();

  uint16_t current = (uint16_t)_emaValue;

  if (cmd == "MIN") {
    _calibMin = current;
    Serial.print("✔ MIN calibrado: ");
    Serial.println(_calibMin);
  }

  if (cmd == "MAX") {
    _calibMax = current;
    Serial.print("✔ MAX calibrado: ");
    Serial.println(_calibMax);
  }
}

void VaslothLightSensor::setCalibration(uint16_t minVal, uint16_t maxVal) {
  _calibMin = minVal;
  _calibMax = maxVal;
}
