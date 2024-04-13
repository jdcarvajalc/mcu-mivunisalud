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
* @brief Constante con el límite del umbral de temperatura establecido por 
* la normatividad vigente. Además, considerando la precisión típica del sensor
*/
extern const float limiteUmbralTemp;
// ****************************************************************************************
/**
* @brief Constante con el límite del umbral de humedad relativa establecido por 
* la normatividad vigente. Además, considerando la precisión típica del sensor
*/
extern const float limiteUmbralHum;
// ****************************************************************************************
/**
* @brief Variable que permite establecer el tipo de alerta que debe generarse
*/
extern int tipoAlerta;
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
* @brief Esta función decide que tipo de alerta es la que se debe generar.
* 
* @param [in] validacionTemp: Bandera de validación de la temperatura
* @param [in] validacionHum: Bandera de validación de la humedad relativa
*/
extern void manejadorTipoAlerta(boolean validacionTemp, boolean validacionHum);
// ****************************************************************************************
/**
* @brief Este servicio se encarga de validar que la temperatura y humedad relativa,
* no superen el valor de los umbrales establecidos por la normatividad
* vigente. Después de realizar la validación, si es el caso, envía los mensajes de alerta
* respectivos al celular del responsable, de forma que pueda actuar de preventivamente.
*/
extern void generarAlertas();
// ****************************************************************************************
#endif