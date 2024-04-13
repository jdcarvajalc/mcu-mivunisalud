#include <Arduino.h>
#include <SPI.h>
#include "almacenamientoMIV.h"
#include "comunicacionesMIV.h"
#include "alertasMIV.h"
#include "relojMIV.h"
#include "sensorMIV.h"

void setup() {
  banderaInicioPlaca = true;
  Serial.begin(115200);
  conectarWifi();
  iniciarSensor();
  iniciarMicroSD();
  actualizarRTC();
  Serial.println("pasé setup");
}

void loop() {
  capturarYGestionarDatos();
  Serial.println("pasé captura datos");
  gestionarTiempo();
  Serial.println("pasé gestión tiempo");
  almacenarDatosLocalmente();
  generarAlertas(); //TODO: almacenar la alerta en microSD para enviarla si no fue enviada con callmebot
  transmitirDatos();
  Serial.println("esperaré siguiente ciclo");
}
