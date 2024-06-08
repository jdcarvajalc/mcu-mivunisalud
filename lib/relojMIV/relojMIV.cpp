// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "relojMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -5 * 3600;
const int daylightOffset_sec = 0;
String date, timestamp;
ESP32Time rtc;
// ****************************************************************************************
void actualizarRTC()
{
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  struct tm timeinfo;
  if (getLocalTime(&timeinfo))
  {
    rtc.setTimeStruct(timeinfo);
  }
}
// ****************************************************************************************
void gestionarTiempo()
{
  date = rtc.getTime("%Y-%m-%d");
  timestamp = rtc.getTime("%H:%M:%S");
}
// ****************************************************************************************
void esperarSiguienteCiclo()
{
  WiFi.disconnect();
  delay(9.85 * 60000); // Tiempo de reposo restando el tiempo de comunicaciones
}
// ****************************************************************************************