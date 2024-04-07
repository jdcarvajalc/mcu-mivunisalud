// ****************************************************************************************
/**
* @file sensorMIV.h
* @brief Biblioteca del sensor de temperatura y humedad usado en el proyecto.
*
* Esta biblioteca contiene las funciones y variables relacionadas con el sensor de
* temperatura y humedad, como la lectura de los valores del sensor, el cálculo del 
* promedio y las variables globales para almacenar los valores promedio.
*/
// ****************************************************************************************
#ifndef SENSOR_H
#define SENSOR_H
// ****************************************************************************************
#include <Wire.h>
#include "Adafruit_SHT31.h"
// ****************************************************************************************
/**
* @brief Instancia del objeto SHT31.
*/
extern Adafruit_SHT31 sht31;
// ****************************************************************************************
/**
* @brief Variable global que almacena el promedio de temperatura calculado.
*/
extern float promedioTemperatura;
// ****************************************************************************************
/**
* @brief Variable global que almacena el promedio de humedad calculado.
*/
extern float promedioHumedad;
// ****************************************************************************************
/**
* @brief Esta función inicializa la comunicación de la MCU con el sensor a través de la
* comunicación I2C, utilizando la dirección 0x44
*/
extern void iniciarSensor();
// ****************************************************************************************
/**
* @brief Esta función lee la temperatura del sensor y la devuelve como un valor flotante.
* @return El valor de temperatura leído.
*/
extern float leerTemperatura();
// ****************************************************************************************
/**
* @brief Esta función lee la humedad del sensor y la devuelve como un valor flotante.
*
* @return El valor de humedad leído.
*/
extern float leerHumedad();
// ****************************************************************************************
/**
* @brief Esta función calcula el promedio de temperatura y humedad a partir de múltiples 
* lecturas del sensor y actualiza las variables globales promedioTemperatura 
* y promedioHumedad.
* 
* @param [in] suma Suma del conjunto de números
* @param [in] cantidadNumeros Cantidad de números en el conjunto
* 
* @return El promedio del conjunto de números
*/
extern float calcularPromedio(float suma, float cantidadNumeros);
// ****************************************************************************************
/**
* @brief Esta función integra las demás funciones para cumplir con los servicios del
* sistema: captura y gestión de datos.
*/
extern void capturarYGestionarDatos();
// ****************************************************************************************
#endif
