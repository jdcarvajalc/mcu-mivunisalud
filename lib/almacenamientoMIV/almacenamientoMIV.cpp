// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "almacenamientoMIV.h"
#include "configMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
const int CHIP_SELECT = 5;
File archivoDatosPermanentes;
// ****************************************************************************************
void iniciarMicroSD()
{
    if (!SD.begin(CHIP_SELECT))
    {
        while (1)
            ;
    }
    archivoDatosPermanentes = SD.open("/datos_permanentes.txt", FILE_APPEND);
    archivoDatosPermanentes.println("area,temp,hum,fecha,hora");
    archivoDatosPermanentes.close();
}
// ****************************************************************************************
void almacenarDatosLocalmente()
{
    String datosAlmacenar = String(identificadorArea) + "," + String(promedioTemperatura) + "," + String(promedioHumedad) + "," + date + "," + timestamp;
    archivoDatosPermanentes = SD.open("/datos_permanentes.txt", FILE_APPEND);
    archivoDatosPermanentes.println(datosAlmacenar);
    archivoDatosPermanentes.close();
    Serial.println("Almacene permanente");
    validarReconexionWifi();
}