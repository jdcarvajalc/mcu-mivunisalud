// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "alertasMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
const float limiteUmbralTemp = 29.7;
const float limiteUmbralHum = 68.0;
int tipoAlerta;
// ****************************************************************************************
boolean validarUmbralTemperatura(){
    boolean entraEnRangoUmbralTemp;
    (promedioTemperatura > limiteUmbralTemp) ? entraEnRangoUmbralTemp = true : entraEnRangoUmbralTemp = false;
    return entraEnRangoUmbralTemp;
}
// ****************************************************************************************
boolean validarUmbralHumedad(){
    boolean entraEnRangoUmbralHum;
    (promedioTemperatura > limiteUmbralHum) ? entraEnRangoUmbralHum = true : entraEnRangoUmbralHum = false;
    return entraEnRangoUmbralHum;
}
// ****************************************************************************************
void manejadorTipoAlerta(boolean validacionTemp, boolean validacionHum){
    if(validacionTemp && validacionHum){
        tipoAlerta = 3;
    }
    else if (validacionTemp){
        tipoAlerta = 1;
    }
    else if (validacionHum){
        tipoAlerta = 2;
    }
    else{
        tipoAlerta = 0;
    }
}
// ****************************************************************************************
void generarAlertas(){
    manejadorTipoAlerta(validarUmbralTemperatura(), validarUmbralHumedad());
    switch(tipoAlerta){
        case 0:
            break;
        case 1:
            enviarMensaje("⚠ ALERTA ⚠\nTemperatura [°C] = " + String(promedioTemperatura));
            break;
        case 2:
            enviarMensaje("⚠ ALERTA ⚠\nHumedad [%] = " + String(promedioHumedad));
            break;
        case 3:
            enviarMensaje("⚠ ALERTA ⚠\nTemperatura [°C] = " + String(promedioTemperatura)+"\nHumedad [%] = "+ String(promedioHumedad));
            break;
    }
}
// ****************************************************************************************