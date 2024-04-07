// ****************************************************************************************
#include "relojMIV.h"
// ****************************************************************************************
// Datos conexión servidor NTP -> Colombia
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -5 * 3600;
const int daylightOffset_sec = 0;
// ****************************************************************************************
ESP32Time rtc;
// ****************************************************************************************
void actualizarRTC() {
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {
    rtc.setTimeStruct(timeinfo);
  }
}
// ****************************************************************************************
void gestionarTiempo(){
  date = rtc.getTime("%Y/%m/%d");
  timestamp = rtc.getTime("%H:%M:%S");
  // TODO: Agregar lo de almacenar en SD 
}
// ****************************************************************************************
void entrarEnDeepSleep() {
  esp_sleep_enable_timer_wakeup(2 * 60 * 1000000);
  esp_deep_sleep_start();
}
// ****************************************************************************************