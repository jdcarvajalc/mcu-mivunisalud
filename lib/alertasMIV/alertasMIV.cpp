#include "alertasMIV.h"
#include "configMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
const float LIMITE_UMBRAL_TEMP = 27.7;
const float LIMITE_UMBRAL_HUM = 63.0;
int tipoAlerta;
// ****************************************************************************************
boolean validarUmbralTemperatura()
{
    return promedioTemperatura > LIMITE_UMBRAL_TEMP;
}
// ****************************************************************************************
boolean validarUmbralHumedad()
{
    return promedioHumedad > LIMITE_UMBRAL_HUM;
}
// ****************************************************************************************
void manejadorTipoAlerta(boolean validacionTemp, boolean validacionHum)
{
    if (validacionTemp && validacionHum)
    {
        tipoAlerta = 3;
    }
    else if (validacionTemp)
    {
        tipoAlerta = 1;
    }
    else if (validacionHum)
    {
        tipoAlerta = 2;
    }
    else
    {
        tipoAlerta = 0;
    }
}
// ****************************************************************************************
void generarAlertas()
{
    boolean validacionTemp = validarUmbralTemperatura();
    boolean validacionHum = validarUmbralHumedad();
    manejadorTipoAlerta(validacionTemp, validacionHum);
    switch (tipoAlerta)
    {
    case 0:
        Serial.println("No se generó ninguna alerta");
        break;
    case 1:
        Serial.println("Superó temp");
        enviarMensaje("⚠ ALERTA ÁREA " + String(identificadorArea) + "⚠\nTemperatura [°C] = " + String(promedioTemperatura));
        break;
    case 2:
        Serial.println("Superó hum");
        enviarMensaje("⚠ ALERTA ÁREA " + String(identificadorArea) + "⚠\nHumedad [%] = " + String(promedioHumedad));
        break;
    case 3:
        Serial.println("Superó ambos");
        enviarMensaje("⚠ ALERTA ÁREA " + String(identificadorArea) + "⚠\nTemperatura [°C] = " + String(promedioTemperatura) + "\nHumedad [%] = " + String(promedioHumedad));
        break;
    }
}
// ****************************************************************************************