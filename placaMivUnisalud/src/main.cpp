#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
#include "sensorMIV.h"
#include "comunicacionesMIV.h"
#include "relojMIV.h"

void setup() {
  Serial.begin(115200);
  conectarWifi();
  while (!sht31.begin(0x44)) {   
    delay(1);
  }
  actualizarRTC();
}

void loop() {
  capturarYGestionarDatos();
  transmitirDatos();
  delay(10000);
  // entrarEnDeepSleep();
}
