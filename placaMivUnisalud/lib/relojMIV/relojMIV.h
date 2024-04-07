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
 * @brief Servidor NTP
 *
 * Dirección del servidor NTP para la sincronización de la hora.
 */
extern const char* ntpServer;
// ****************************************************************************************
/**
 * @brief Desplazamiento horario GMT
 *
 * Desplazamiento horario en segundos con respecto al horario GMT (Greenwich Mean Time).
 */
extern const long gmtOffset_sec;
// ****************************************************************************************
/**
 * @brief Desplazamiento horario de verano
 *
 * Desplazamiento horario en segundos para tener en cuenta el horario de verano.
 */
extern const int daylightOffset_sec;
// ****************************************************************************************
/**
 * @brief RTC (Real-Time Clock)
 *
 * Instancia del objeto RTC (Real-Time Clock) utilizado para el manejo del tiempo.
 */
extern ESP32Time rtc;
// ****************************************************************************************
/**
 * @brief Actualiza el RTC (Real-Time Clock)
 *
 * Esta función actualiza el RTC (Real-Time Clock) utilizando la sincronización de hora
 * a través del servidor NTP y los desplazamientos horarios configurados.
 */
extern void actualizarRTC();
// ****************************************************************************************
/**
 * @brief Entra en el modo de suspensión (deep sleep)
 *
 * Esta función hace que el dispositivo entre en el modo de suspensión (deep sleep)
 * para reducir el consumo de energía.
 */
extern void entrarEnDeepSleep();
// ****************************************************************************************
#endif