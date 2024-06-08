// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "almacenamientoMIV.h"
#include "configMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
const int CHIP_SELECT = 5;
File archivoDatosPermanentes, archivoDatosURL, archivoDatosAlerta;
bool sdIniciada = false;
// ****************************************************************************************
void iniciarMicroSD()
{
    int contador = 0;
    while (!SD.begin(CHIP_SELECT) && contador < 5000)
    {
        delay(1);
        contador++;
    }
    if (contador == 5000)
    {
        sdIniciada = false;
        return;
    }
    archivoDatosPermanentes = SD.open("/datos_permanentes.txt", FILE_APPEND);
    if (!archivoDatosPermanentes)
    {
        sdIniciada = false;
        return;
    }
    archivoDatosPermanentes.println("area,temp,hum,fecha,hora");
    archivoDatosPermanentes.close();
    sdIniciada = true;
}
// ****************************************************************************************
void almacenarDatosLocalmente()
{
    if (!sdIniciada)
    {
        return;
    }
    String datosAlmacenar = String(identificadorArea) + "," + String(promedioTemperatura) + "," + String(promedioHumedad) + "," + date + "," + timestamp;
    archivoDatosPermanentes = SD.open("/datos_permanentes.txt", FILE_APPEND);
    if (!archivoDatosPermanentes)
    {
        return;
    }
    archivoDatosPermanentes.println(datosAlmacenar);
    archivoDatosPermanentes.close();
    Serial.println("Almacene permanente");
    validarReconexionWifi();
}
// ****************************************************************************************
void almacenarAlertaFallida(String mensaje)
{
    if (!sdIniciada)
    {
        return;
    }
    archivoDatosAlerta = SD.open("/alertas_fallidas.txt", FILE_APPEND);
    if (!archivoDatosAlerta)
    {
        return;
    }
    archivoDatosAlerta.println(mensaje);
    archivoDatosAlerta.close();
}
// ****************************************************************************************
void almacenarTransmisionFallida(String data)
{
    if (!sdIniciada)
    {
        return;
    }
    archivoDatosURL = SD.open("/transmision_fallida.txt", FILE_APPEND);
    if (!archivoDatosURL)
    {
        return;
    }
    archivoDatosURL.println(data);
    archivoDatosURL.close();
}