// ****************************************************************************************
/**
 * @file comunicacionesMIV.h
 * @brief Biblioteca de comunicaciones usadas en el proyecto.
 *
 * Esta biblioteca contiene las funciones y variables relacionadas con las comunicaciones.
 */
// ****************************************************************************************
#ifndef COMUNICACIONES_H
#define COMUNICACIONES_H
// ****************************************************************************************
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <UrlEncode.h>
#include <SD.h>
#include "sensorMIV.h"
#include "relojMIV.h"
// ****************************************************************************************
/**
 * @brief Bandera para saber si es necesario conectarse nuevamente a la red o no.
 */
extern boolean banderaInicioPlaca;
// ****************************************************************************************
/**
 * @brief Esta función conecta
 */
extern void conectarWifi();
// ****************************************************************************************
/**
 * @brief Esta función valida si es necesario reconectar el Wifi
 */
extern void validarReconexionWifi();
// ****************************************************************************************
/**
 * @brief Esta función envía
 *
 * @param [in] mensaje: Mensaje a enviar
 */
extern void enviarMensaje(String mensaje);
// ****************************************************************************************
/**
 * @brief Esta función construye
 *
 * @return La url completa para la petición
 */
extern String construirURLDatos();
// ****************************************************************************************
/**
 * @brief Esta función transmite
 */
extern void transmitirDatos();
// ****************************************************************************************
#endif
