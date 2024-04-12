// ****************************************************************************************
#include "alertasMIV.h"
// ****************************************************************************************
void generarAlertas(){
    boolean superaUmbralTemp, superaUmbralHum;
    (promedioTemperatura > 27.7) ? superaUmbralTemp = true : superaUmbralTemp = false;
    (promedioHumedad > 63.0) ? superaUmbralHum = true : superaUmbralHum = false;
}