// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "alertasMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
const float limiteUmbralTemp = 29.7;
const float limiteUmbralHum = 68.0;
int tipoAlerta;
// ****************************************************************************************
boolean validarUmbralTemperatura()
{
    return promedioTemperatura > limiteUmbralTemp;
}
// ****************************************************************************************
boolean validarUmbralHumedad()
{
    return promedioHumedad > limiteUmbralHum;
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
        enviarMensaje("⚠ ALERTA ⚠\nTemperatura [°C] = " + String(promedioTemperatura));
        break;
    case 2:
        Serial.println("Superó hum");
        enviarMensaje("⚠ ALERTA ⚠\nHumedad [%] = " + String(promedioHumedad));
        break;
    case 3:
        Serial.println("Superó ambos");
        enviarMensaje("⚠ ALERTA ⚠\nTemperatura [°C] = " + String(promedioTemperatura) + "\nHumedad [%] = " + String(promedioHumedad));
        break;
    }
}
// ****************************************************************************************
