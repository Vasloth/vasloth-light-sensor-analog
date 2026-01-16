#ifndef VASLOTH_LIGHT_SENSOR_H
#define VASLOTH_LIGHT_SENSOR_H

#include <Arduino.h>

class VaslothLightSensor {
public:
  VaslothLightSensor(uint8_t pin);

  void begin();

  uint16_t readRawFiltered();   // ADC filtrado + EMA
  uint8_t  readPercent();       // 0–100 %

  void handleSerialCalibration();
  void setCalibration(uint16_t minVal, uint16_t maxVal);

private:
  uint8_t _pin;

  // --- Calibración ---
  uint16_t _calibMin = 50;
  uint16_t _calibMax = 3800;

  // --- EMA ---
  float _emaValue = 0.0f;
  bool _started = false;

  // --- Constantes internas ---
  static const uint8_t OVERSAMPLE_COUNT = 32;
  static const uint8_t DISCARD_SAMPLES  = 4;
  static constexpr float EMA_ALPHA = 0.05f;
  static const uint16_t DEADZONE = 10;

  uint16_t readADCProcessed();
  uint8_t  mapLight(uint16_t value);
};

#endif
