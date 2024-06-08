// ****************************************************************************************
/**
 * @file sensorMIV.h
 * @brief Esta biblioteca contiene las funciones y variables relacionadas con el sensor de
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
 * @brief En primer lugar este servicio lee 101 valores de temperatura
 * y 101 valores de humedad relativa. En segundo lugar realiza el promedio de estos
 * leidos, realizando la validación de estos para evitar valores nulos o ceros. Finalmente,
 * almacena los valores de los promedios en variables globales
 * para ser utilizados posteriormente.
 */
extern void capturarYGestionarDatos();
// ****************************************************************************************
#endif
