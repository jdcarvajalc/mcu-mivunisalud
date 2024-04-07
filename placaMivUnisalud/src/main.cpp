#include <Arduino.h>
#include <SPI.h>
#include "sensorMIV.h"
#include "comunicacionesMIV.h"
#include "relojMIV.h"

void setup() {
  Serial.begin(115200);
  conectarWifi();
  iniciarSensor();
  actualizarRTC();
}

void loop() {
  capturarYGestionarDatos();
  transmitirDatos();
  // delay(10000);
  entrarEnDeepSleep();
}
