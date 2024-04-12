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
#include "sensorMIV.h"
#include "almacenamientoMIV.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <UrlEncode.h>
// ****************************************************************************************
/**
* @brief Constante con el límite inferior del umbral de temperatura establecido por la 
* normatividad vigente.
*/
extern const float limiteInferiorUmbralTemp;
// ****************************************************************************************
/**
* @brief Constante con el límite inferior del umbral de humedad relativa
* establecido por la normatividad vigente.
*/
extern const float limiteInferiorUmbralHum;
// ****************************************************************************************
/**
* @brief Esta función valida si el promedio de la temperatura supera el límite 
* inferior del umbral de temperatura estipulado por la normatividad vigente
* 
* @return Validación de si la temperatua entra o no al rango del umbral 
* de temperatura.
*/
extern boolean validarUmbralTemperatura();
// ****************************************************************************************
/**
* @brief Esta función valida si el promedio de la humedad relativa supera el límite 
* inferior del umbral de humedad relativa estipulado por la normatividad vigente
* 
* @return Validación de si la humedad relativa entra o no al rango del umbral 
* de humedad relativa.
*/
extern boolean validarUmbralHumedad();
// ****************************************************************************************
/**
* @brief Esta función construye el mensaje de alerta de temperatura
* para enviarlo al responsable
* 
* @param [in] estaEnRango: Bandera que indica si se encuentra en el rango del
* umbral de temperatura
*/
extern void alertaTemperatura(boolean estaEnRango);
// ****************************************************************************************
/**
* @brief Esta función construye el mensaje de alerta de humedad relativa
* para enviarlo al responsable
* 
* @param [in] estaEnRango: Bandera que indica si se encuentra en el rango del
* umbral de humedad relativa
*/
extern void alertaHumedad(boolean estaEnRango);
// ****************************************************************************************
/**
* @brief Este servicio se encarga de validar que la temperatura y humedad relativa,
* no superen el valor de límite inferior de los umbrales establecidos por la normatividad
* vigente. Después de realizar la validación, si es el caso, envía los mensajes de alerta
* respectivos al celular del responsable, de forma que pueda actuar de preventivamente.
*/
extern void generarAlertas();
// ****************************************************************************************
#endif