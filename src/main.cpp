#include <Arduino.h>
#include <SPI.h>
#include "configMIV.h"
#include "almacenamientoMIV.h"
#include "comunicacionesMIV.h"
#include "alertasMIV.h"
#include "relojMIV.h"
#include "sensorMIV.h"

void setup()
{
  banderaInicioPlaca = true;
  Serial.begin(115200);
  conectarWifi();
  iniciarSensor();
  iniciarMicroSD();
  actualizarRTC();
}

void loop()
{
  capturarYGestionarDatos();
  gestionarTiempo();
  almacenarDatosLocalmente();
  generarAlertas();
  transmitirDatos();
}
