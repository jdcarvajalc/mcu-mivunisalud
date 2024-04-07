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
  gestionarTiempo(); // TODO: Agregar lo de almacenar en SD permanentemente
  //generarAlertas();
  // (WiFi.status() == WL_CONNECTED) ? transmitirDatos() : almacenarDatosLocalmente();
  if(WiFi.status() == WL_CONNECTED){
    transmitirDatos();
  }
  else{
    //almacenarDatosLocalmente();
  }
  
  
  entrarEnDeepSleep();
}
