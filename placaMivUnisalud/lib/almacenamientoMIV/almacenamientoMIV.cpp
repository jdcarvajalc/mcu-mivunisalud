// ****************************************************************************************
#include "almacenamientoMIV.h"
// ****************************************************************************************
const int chipSelect = 5;
File archivoDatosPermanentes, archivoDatosTemporales;
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
void almacenarEnArchivoPermanente(String ruta, String datos){
    archivoDatosPermanentes = SD.open(ruta, FILE_APPEND);
    archivoDatosPermanentes.println(datos);
    archivoDatosPermanentes.close();
    Serial.println("Almacene permanente");
}
// ****************************************************************************************
void almacenarDatosLocalmente(){
    String guardarURL = construirURLDatos();
    archivoDatosTemporales = SD.open("/temporales.txt", FILE_APPEND);
    archivoDatosTemporales.println(guardarURL);
    archivoDatosTemporales.close();
    Serial.println("Almacene temporalmente");

}