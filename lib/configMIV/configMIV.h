// ****************************************************************************************
/**
 * @file configMIV.h
 * @brief Biblioteca de configuración de credenciales usadas en el proyecto.
 */
// ****************************************************************************************
#ifndef CONFIGMIV_H
#define CONFIGMIV_H
// ****************************************************************************************
#include <Arduino.h>
// ****************************************************************************************
/**
 * @brief Constante del nombre de la red WiFi a la que será conectada la ESP32.
 */
extern const char *WIFI_SSID;
// ****************************************************************************************
/**
 * @brief Constante de la contraseña de la red WiFi a la que será conectada la ESP32.
 */
extern const char *WIFI_PASSWORD;
// ****************************************************************************************
/**
 * @brief Constante de la URL de la aplicación web para el envío y registro de datos.
 */
extern const char *WEB_APP_URL;
// ****************************************************************************************
/**
 * @brief Número de celular del responsable, necesario para enviar los mensajes de alertas
 * a WhatsApp.
 */
extern String phoneNumber;
// ****************************************************************************************
/**
 * @brief Llave de la API proporcionada por CallMeBot para poder realizar el envío
 * de mensajes a WhatsApp.
 */
extern String apiKey;
// ****************************************************************************************
/**
 * @brief Número de identificación del área de la farmacia donde se encuentra el nodo IoT.
 */
extern int identificadorArea;
// ****************************************************************************************
#endif
