// ****************************************************************************************
/**
 * @file relojMIV.h
 * @brief Biblioteca del reloj y gestión del tiempo
 *
 * Esta biblioteca contiene funciones y variables relacionadas con el reloj y el manejo del tiempo,
 * como la obtención de la hora a través de un servidor NTP, la actualización del RTC (Real-Time Clock),
 * y el modo de suspensión (deep sleep).
 */
// ****************************************************************************************
#ifndef RELOJ_H
#define RELOJ_H
// ****************************************************************************************
#include <ESP32Time.h>
// ****************************************************************************************
/**
 * @brief Dirección del servidor NTP para la sincronización de la hora.
 */
extern const char* ntpServer;
// ****************************************************************************************
/**
 * @brief Desplazamiento horario en segundos con respecto al horario GMT (Greenwich Mean Time).
 */
extern const long gmtOffset_sec;
// ****************************************************************************************
/**
 * @brief Desplazamiento horario en segundos para tener en cuenta el horario de verano.
 */
extern const int daylightOffset_sec;
// ****************************************************************************************
/**
 * @brief Instancia del objeto RTC (Real-Time Clock) utilizado para el manejo del tiempo.
 */
extern ESP32Time rtc;
// ****************************************************************************************
/**
 * @brief Fecha de captura del dato de temperatura y humedad relativa
 */
extern String date;
// ****************************************************************************************
/**
 * @brief Marca temporal de captura del dato de temperatura y humedad relativa
 */
extern String timestamp;
// ****************************************************************************************
/**
 * @brief Esta función actualiza el RTC (Real-Time Clock) utilizando la sincronización 
 * de hora a través del servidor NTP y los desplazamientos horarios configurados.
 */
extern void actualizarRTC();
// ****************************************************************************************
/**
 * @brief Esta función obtiene la fecha y horas de la captura de los datos de temperatura y
 * humedad relativa, a través del RTC
 */
extern void gestionarTiempo();
// ****************************************************************************************
/**
 * @brief Esta función configura el modo de suspensión profunda en la ESP32 y 
 * establece el tiempo de espera para despertar. En este caso, se establece un
 * tiempo de espera de 10 minutos antes de que la ESP32 se despierte.
 */
extern void entrarEnDeepSleep();
// ****************************************************************************************
#endif