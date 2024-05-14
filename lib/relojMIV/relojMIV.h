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
#include "comunicacionesMIV.h"
#include "almacenamientoMIV.h"
#include "WiFi.h"
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <UrlEncode.h>
#include <ESP32Time.h>
#include <sys/time.h>
#include <SD.h>
#include "sensorMIV.h"
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
 * @brief Esta función configura el entorno de la MCU para esperar un tiempo determinado,
 * hasta que sea necesario hacer la siguiente medición.
 */
extern void esperarSiguienteCiclo();
// ****************************************************************************************
#endif