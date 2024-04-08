// ****************************************************************************************
#include "relojMIV.h"
// ****************************************************************************************
// Datos conexión servidor NTP -> Colombia
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -5 * 3600;
const int daylightOffset_sec = 0;
// ****************************************************************************************
String date, timestamp;
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
  date = rtc.getTime("%Y-%m-%d");
  timestamp = rtc.getTime("%H:%M:%S");
  String datosAlmacenar = String(promedioTemperatura) 
                          + "," 
                          + String(promedioHumedad) 
                          + "," 
                          + date 
                          + "," 
                          + timestamp;
  almacenarEnArchivoPermanente("/datos_permanentes.txt", datosAlmacenar);
  validarReconexionWifi();
}
// ****************************************************************************************
void esperarSiguienteCiclo() {
  WiFi.disconnect();
  delay(1.9*60000);//Tiempo de reposo restando el tiempo de comunicaciones
}
// ****************************************************************************************