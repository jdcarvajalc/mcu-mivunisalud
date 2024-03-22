#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
#include "sensorMIV.h"

// Nombre de la red WiFi
const char* ssid = "MarcElvia";
// Contraseña de la red WiFi
const char* password = "R2S3T9S,";

void setup() {
  Serial.begin(115200);

  if (!sht31.begin(0x44)) {   
    Serial.println("Sensor no conectado");
    while (1) delay(1);
  }

  // Conectarse a WiFi
  Serial.print("Conectando a WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado!");
}

void loop() {
  capturarYGestionarDatos();
}
