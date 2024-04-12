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

    // Liberar recursos
    http.end();
}
// ****************************************************************************************
String construirURLDatos() {
  String urlDatos = "temp=" + String(promedioTemperatura) + "&hum=" + String(promedioHumedad) + "&date=" + date + "&timestamp=" + timestamp;
  return urlDatos;
}
// ****************************************************************************************
void transmitirDatos(){
    Serial.println("Mandando datos");
    String data = construirURLDatos();

    WiFiClientSecure *client = new WiFiClientSecure;
    client -> setInsecure();
    HTTPClient https;

    https.begin(*client, serverURL);

    https.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Enviar petición HTTPS de tipo POST
    int httpResponseCode = https.POST(data);

    if (httpResponseCode != 200) {
        //TODO: función en sd que almacene las veces que no ha sido exitoso el envío
    }
    // Liberar recursos
    https.end();
    esperarSiguienteCiclo();
}
// ****************************************************************************************