#include <Arduino.h>
#include <VaslothLightSensor.h>

#define LDR_PIN 35

VaslothLightSensor lightSensor(LDR_PIN);

void setup() {
  Serial.begin(9600);
  delay(1000);

  lightSensor.begin();

  Serial.println("Sensor de Luz Vasloth");
  Serial.println("Comandos por Serial:");
  Serial.println("  MIN -> calibrar oscuridad");
  Serial.println("  MAX -> calibrar luz maxima");
}

void loop() {
  uint8_t luz = lightSensor.readPercent();

  Serial.print("Luz: ");
  Serial.print(luz);
  Serial.println(" %");

  lightSensor.handleSerialCalibration();

  delay(300);
}
