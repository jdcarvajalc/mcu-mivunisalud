// ****************************************************************************************
/**
* @file almacenamientoMIV.h
* @brief Biblioteca de servicios y funciones de almacenamiento del proyecto.
*/
// ****************************************************************************************
#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H
// ****************************************************************************************
#include <Wire.h>
#include <SD.h>
#include "comunicacionesMIV.h"
// ****************************************************************************************
/**
* @brief Constante global del pin de selección del módulo MicroSD
*/
extern const int chipSelect;
// ****************************************************************************************
/**
* @brief Objeto de tipo archivo para el fichero en el que se guardarán los datos
* permanentemente.
*/
extern File archivoDatosPermanentes;
// ****************************************************************************************
/**
* @brief Objeto de tipo archivo para el fichero en el que se guardarán los datos 
* temporalmente.
*/
extern File archivoDatosTemporales;
// ****************************************************************************************
/**
* @brief Esta función inicializa la comunicación de la MCU con el módulo micro SD
* a través de la comunicación SPI
*/
extern void iniciarMicroSD();
// ****************************************************************************************
/**
* @brief Este servicio ...
*/
extern void almacenarDatosLocalmente();
// ****************************************************************************************
#endif
