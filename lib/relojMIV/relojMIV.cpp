// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "relojMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
const char *NTP_SERVER = "pool.ntp.org";
const long GMT_OFFSET_SEC = -5 * 3600;
const int DAYLIGHT_OFFSET_SEC = 0;
String date, timestamp;
ESP32Time rtc;
// ****************************************************************************************
void actualizarRTC()
{
  configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
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