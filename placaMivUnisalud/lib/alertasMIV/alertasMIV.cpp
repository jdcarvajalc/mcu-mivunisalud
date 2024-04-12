// ****************************************************************************************
#include "alertasMIV.h"
// ****************************************************************************************
const float limiteInferiorUmbralTemp = 28.0;
const float limiteInferiorUmbralHum = 65.0;
// ****************************************************************************************
boolean validarUmbralTemperatura(){
    boolean entraEnRangoUmbralTemp;
    (promedioTemperatura > limiteInferiorUmbralTemp) ? entraEnRangoUmbralTemp = true : entraEnRangoUmbralTemp = false;
    return entraEnRangoUmbralTemp;
}
// ****************************************************************************************
boolean validarUmbralHumedad(){
    boolean entraEnRangoUmbralHum;
    (promedioTemperatura > limiteInferiorUmbralHum) ? entraEnRangoUmbralHum = true : entraEnRangoUmbralHum = false;
    return entraEnRangoUmbralHum;
}
// ****************************************************************************************
void alertaTemperatura(boolean estaEnRango){
    if(estaEnRango){
        enviarMensaje("⚠ Entrando a rango del umbral de temperatura ⚠ Temperatura [°C] = " + String(promedioTemperatura));
    }
}
// ****************************************************************************************
void alertaHumedad(boolean estaEnRango){
    if(estaEnRango){
        enviarMensaje("⚠ Entrando a rango del umbral de humedad ⚠ Humedad [%] = " + String(promedioHumedad));
    }
}
// ****************************************************************************************
void generarAlertas(){
    alertaTemperatura(validarUmbralTemperatura());
    alertaHumedad(validarUmbralHumedad());
}
// ****************************************************************************************