#include <VaslothLightSensor.h>

VaslothLightSensor lightSensor(35);

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
  Serial.print("Luz: ");
  Serial.print(lightSensor.readPercent());
  Serial.println(" %");

  lightSensor.handleSerialCalibration();
  delay(300);
}
