// ****************************************************************************************
/**
 * @file alertasMIV.h
 * @brief Biblioteca de las alertas del sistema
 *
 * Esta biblioteca contiene funciones y variables relacionadas con la gestión de alertas
 * del sistema, específicamente para validación de umbrales de temperatura y humedad 
 * relativa cuando sea necesario, de forma que la persona responsable pueda actuar de forma
 * preventiva, ante escenarios no deseados.
 */
// ****************************************************************************************
#ifndef ALERTS_H
#define ALERTS_H
// ****************************************************************************************
#include "comunicacionesMIV.h"
#include "almacenamientoMIV.h"
#include "sensorMIV.h"
#include "WiFi.h"
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <UrlEncode.h>
#include <ESP32Time.h>
#include <sys/time.h>
#include <SD.h>
// ****************************************************************************************
/**
 * @brief Dirección del servidor NTP para la sincronización de la hora.
 */
extern const char* ntpServer;
// ****************************************************************************************
/**
 * @brief Esta función configura el entorno de la MCU para esperar un tiempo determinado,
 * hasta que sea necesario hacer la siguiente medición.
 */
extern void generarAlertas();
// ****************************************************************************************
#endif