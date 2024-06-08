// ****************************************************************************************
/**
 * @file comunicacionesMIV.h
 * @brief Biblioteca de comunicaciones del proyecto.
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
 * @brief Esta función conecta la ESP32 a una red WiFi configurada en el archivo
 * configMIV.cpp
 */
extern void conectarWifi();
// ****************************************************************************************
/**
 * @brief Esta función valida si es necesario reconectar el WiFi.
 */
extern void validarReconexionWifi();
// ****************************************************************************************
/**
 * @brief Esta función transmite un mensaje de alerta a CallMeBot para que sea enviado por
 * medio de la API de WhatsApp al celular del responsable.
 *
 * @param [in] mensaje: Mensaje a enviar
 */
extern void enviarMensaje(String mensaje);
// ****************************************************************************************
/**
 * @brief Esta función construye la URL de datos para enviar a través del método POST
 * de HTTP a la aplicación web.
 *
 * @return La url completa para la petición
 */
extern String construirURLDatos();
// ****************************************************************************************
/**
 * @brief En primer lugar este servicio construye el URL de datos de área, temperatura,
 * humedad relativa, fecha y marca temporal. En segundo lugar, verifica que haya conexión
 * WiFI para enviar los datos a la aplicación web. Finalmente, libera recursos de la
 * comunicación WiFi para esperar el siguiente ciclo (10 minutos).
 */
extern void transmitirDatos();
// ****************************************************************************************
#endif
