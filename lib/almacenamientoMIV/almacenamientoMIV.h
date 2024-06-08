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
#include "configMIV.h"
#include "comunicacionesMIV.h"
// ****************************************************************************************
/**
 * @brief Constante global del pin de selección del módulo MicroSD
 */
extern const int CHIP_SELECT;
// ****************************************************************************************
/**
 * @brief Objeto de tipo archivo para el fichero en el que se guardarán los datos
 * permanentemente.
 */
extern File archivoDatosPermanentes;
// ****************************************************************************************
/**
 * @brief Esta función inicializa la comunicación de la MCU con el módulo micro SD
 * a través de la comunicación SPI
 */
extern void iniciarMicroSD();
// ****************************************************************************************
/**
 * @brief Este servicio almacena en la tarjeta microSD los datos de área, temperatura,
 * humedad relativa, fecha y marca temporal. Garantizando disponibilidad y completitud
 * de los datos, sirviendo como respaldo por si la comunicación con la aplicación web falla.
 */
extern void almacenarDatosLocalmente();
// ****************************************************************************************
#endif
