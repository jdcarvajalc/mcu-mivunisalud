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
#include "sensorMIV.h"
#include "relojMIV.h"
// ****************************************************************************************
/**
* @brief Constante global que 
*/
extern const char* SSID;
// ****************************************************************************************
/**
* @brief Constante global que 
*/
extern const char* PASSWORD;
// ****************************************************************************************
/**
* @brief Constante global que contiene la URL del servidor para registrar datos
*/
extern const char* serverURL;
// ****************************************************************************************
/**
* @brief Variable global que 
*/
extern String phoneNumber;
// ****************************************************************************************
/**
* @brief Variable global que 
*/
extern String apiKey;
// ****************************************************************************************
/**
* @brief Esta función conecta
*/
extern void conectarWifi();
// ****************************************************************************************
/**
* @brief Esta función envía
* 
* @param [in] mensaje: Mensaje a enviar
*/
extern void enviarMensaje(String mensaje);
// ****************************************************************************************
/**
* @brief Esta función transmite
* 
* @return Bandera de confirmación de transmisión
*/
extern boolean transmitirDatos();
// ****************************************************************************************
#endif
