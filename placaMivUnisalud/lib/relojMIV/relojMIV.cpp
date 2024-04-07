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
/**
* @brief Actualiza el RTC (Real-Time Clock)
*
* Esta función actualiza la configuración del RTC (Real-Time Clock) utilizando el
* servidor NTP especificado en la constante ntpServer. Luego, obtiene la hora actual del 
* servidor NTP y actualiza el RTC interno de la ESP32 con esta información.
*/
void actualizarRTC() {
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {
    rtc.setTimeStruct(timeinfo);
  }
}
// ****************************************************************************************
/**
* @brief Entra en el modo de suspensión profunda
*
* Esta función configura el modo de suspensión profunda en la ESP32 y establece el tiempo
* de espera para despertar. En este caso, se establece un tiempo de espera de 5 minutos
* antes de que la ESP32 se despierte.
*/
void entrarEnDeepSleep() {
  esp_sleep_enable_timer_wakeup(2 * 60 * 1000000);
  esp_deep_sleep_start();
}
// ****************************************************************************************