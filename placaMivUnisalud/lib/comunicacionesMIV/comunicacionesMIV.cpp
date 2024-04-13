// ****************************************************************************************
#include "comunicacionesMIV.h"
// ****************************************************************************************
boolean banderaInicioPlaca;
const char* SSID = "MarcElvia";
const char* PASSWORD = "R2S3T9S,";
const char* serverURL = "https://pruebasmiv.000webhostapp.com/api/almacenarDatosTemperaturaHumedad.php";
String phoneNumber = "+573202897345";
String apiKey = "5249216";
// ****************************************************************************************
void conectarWifi(){
    WiFi.begin(SSID, PASSWORD);
    while(WiFi.status() != WL_CONNECTED) {
        delay(1);
    }
}
// ****************************************************************************************
void validarReconexionWifi(){
    int contador = 0;
    if(banderaInicioPlaca){
        banderaInicioPlaca = false;
    }
    else{
        WiFi.begin(SSID, PASSWORD);
        while(WiFi.status() != WL_CONNECTED && contador < 10000){
            contador++;
            delay(1); // Retardo entre cada intento de conexión
        }
    }
}
// ****************************************************************************************
void enviarMensaje(String mensaje){
    if(WiFi.status() == WL_CONNECTED){
        // Data to send with HTTP POST
        String url = "https://api.callmebot.com/whatsapp.php?phone=" 
                    + phoneNumber 
                    + "&apikey=" 
                    + apiKey 
                    + "&text=" 
                    + urlEncode(mensaje);    
        HTTPClient http;
        http.begin(url);
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        // Enviar petición HTTP de tipo POST 
        int httpResponseCode = http.POST(url);
        Serial.println(httpResponseCode);
        if(httpResponseCode != 200){
            
            //almacenarAlertaFallida();
        }
        // Liberar recursos
        http.end();
    }
}
// ****************************************************************************************
String construirURLDatos() {
  String urlDatos = "temp=" + String(promedioTemperatura) + "&hum=" + String(promedioHumedad) + "&date=" + date + "&timestamp=" + timestamp;
  return urlDatos;
}
// ****************************************************************************************
void transmitirDatos(){
    if(WiFi.status() == WL_CONNECTED){
        Serial.println("Mandando datos");
        String data = construirURLDatos();

        HTTPClient https;

        https.begin(serverURL);

        https.addHeader("Content-Type", "application/x-www-form-urlencoded");

        // Enviar petición HTTPS de tipo POST
        int httpResponseCode = https.POST(data);

        // Liberar recursos
        https.end();
        esperarSiguienteCiclo();
    }
    else{
        esperarSiguienteCiclo();
    }
}
// ****************************************************************************************