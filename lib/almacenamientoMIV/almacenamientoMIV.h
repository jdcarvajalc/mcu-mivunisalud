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
extern File archivoDatosURL;
extern File archivoDatosAlerta;
// ****************************************************************************************
/**
 * @brief Esta función inicializa la comunicación de la MCU con el módulo micro SD
 * a través de la comunicación SPI
 */
extern void iniciarMicroSD();
// ****************************************************************************************
/**
 * @brief Esta función almacena el mensaje que no pudo enviarse.
 *
 * @param [in] mensaje: Mensaje de alerta que no puedo ser transmitido al responsable
 */
extern void almacenarAlertaFallida(String mensaje);
// ****************************************************************************************
/**
 * @brief Esta función almacena la url de la transmisión fallida.
 *
 * @param [in] data: Url de los datos para el método POST
 */
extern void almacenarTransmisionFallida(String data);
// ****************************************************************************************
/**
 * @brief Este servicio almacena en la tarjeta microSD los datos de área, temperatura,
 * humedad relativa, fecha y marca temporal. Garantizando disponibilidad y completitud
 * de los datos, sirviendo como respaldo por si la comunicación con la aplicación web falla.
 */
extern void almacenarDatosLocalmente();
// ****************************************************************************************
#endif
