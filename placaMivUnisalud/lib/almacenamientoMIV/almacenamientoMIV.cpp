// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "almacenamientoMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
const int chipSelect = 5;
File archivoDatosPermanentes;
// ****************************************************************************************
void iniciarMicroSD(){
    if (!SD.begin(chipSelect)) {
        while (1);
    }
    archivoDatosPermanentes = SD.open("/datos_permanentes.txt", FILE_APPEND);
    archivoDatosPermanentes.println("temp,hum,fecha,hora");
    archivoDatosPermanentes.close();
}
// ****************************************************************************************
void almacenarDatosLocalmente(){
    String datosAlmacenar = String(promedioTemperatura) 
                            + "," 
                            + String(promedioHumedad) 
                            + "," 
                            + date 
                            + "," 
                            + timestamp;
    archivoDatosPermanentes = SD.open("/datos_permanentes.txt", FILE_APPEND);
    archivoDatosPermanentes.println(datosAlmacenar);
    archivoDatosPermanentes.close();
    Serial.println("Almacene permanente");
    validarReconexionWifi();
}