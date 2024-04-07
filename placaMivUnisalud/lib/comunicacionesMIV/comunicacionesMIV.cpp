// ****************************************************************************************
#include "comunicacionesMIV.h"
// ****************************************************************************************
/**
* @brief Constante de identificador de red 
*/
const char* SSID = "MarcElvia";
// ****************************************************************************************
/**
* @brief Constante de contraseña de red 
*/
const char* PASSWORD = "R2S3T9S,";
// ****************************************************************************************
/**
* @brief Constante de URL del servidor para registro de datos 
*/
const char* serverURL = "https://pruebasmiv.000webhostapp.com/api/almacenarDatosTemperaturaHumedad.php";
/**
* @brief Variable global que 
*/
String phoneNumber = "+573202897345";
// ****************************************************************************************
/**
* @brief Variable global que 
*/
String apiKey = "5249216";
// ****************************************************************************************
/**
* @brief Esta función conecta
*/
extern void conectarWifi(){
    WiFi.begin(SSID, PASSWORD);
    while(WiFi.status() != WL_CONNECTED) {
        delay(1);
    }
}
// ****************************************************************************************
/**
* @brief Esta función envía
* 
* @param [in] mensaje: Mensaje a enviar
*/
extern void enviarMensaje(String mensaje){
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
/**
 * @brief Construye la URL de los datos
 *
 * Esta función construye la URL de los datos a enviar. Utiliza el objeto rtc para obtener
 * la fecha y hora actual y combina los valores de temperatura, humedad, fecha y hora en 
 * una cadena de consulta.
 *
 * @return La URL de los datos.
 */
String construirURLDatos() {
  String date = rtc.getTime("%Y/%m/%d");
  String timestamp = rtc.getTime("%H:%M:%S");
  String urlDatos = "temp=" + String(promedioTemperatura) + "&hum=" + String(promedioHumedad) + "&date=" + date + "&timestamp=" + timestamp;
  return urlDatos;
}
// ****************************************************************************************
/**
* @brief Esta función transmite
* 
* @return Bandera de confirmación de transmisión
*/
extern boolean transmitirDatos(){
    String data = construirURLDatos();
    if(WiFi.status() == WL_CONNECTED){
        WiFiClientSecure *client = new WiFiClientSecure;
        client -> setInsecure();
        HTTPClient https;

        https.begin(*client, serverURL);

        https.addHeader("Content-Type", "application/x-www-form-urlencoded");

        // Enviar petición HTTPS de tipo POST
        int httpResponseCode = https.POST(data);

        if (httpResponseCode == 200) {
            return true;
        }
        else {
            return false;
        }
        // Liberar recursos
        https.end();
        
    }
    else {
        return false;
    }
}
// ****************************************************************************************