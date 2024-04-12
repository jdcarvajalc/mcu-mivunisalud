// ****************************************************************************************
#include "alertasMIV.h"
// ****************************************************************************************
void generarAlertas(){
    boolean entraEnRangoUmbralTemp, entraEnRangoUmbralHum;
    (promedioTemperatura > 28.0) ? entraEnRangoUmbralTemp = true : entraEnRangoUmbralTemp = false;
    (promedioHumedad > 65.0) ? entraEnRangoUmbralHum = true : entraEnRangoUmbralHum = false;
    if(entraEnRangoUmbralTemp){
        enviarMensaje("⚠ Entrando a rango del umbral de temperatura ⚠ Temperatura [°C] = " + String(promedioTemperatura));
    }
    if(entraEnRangoUmbralHum){
        enviarMensaje("⚠ Entrando a rango del umbral de humedad ⚠ Humedad [%] = " + String(promedioHumedad));
    }
}