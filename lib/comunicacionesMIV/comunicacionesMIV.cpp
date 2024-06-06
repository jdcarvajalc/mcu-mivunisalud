// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "comunicacionesMIV.h"
#include "configMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
boolean banderaInicioPlaca;
// ****************************************************************************************
void conectarWifi()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1);
    }
}
// ****************************************************************************************
void validarReconexionWifi()
{
    int contador = 0;
    if (banderaInicioPlaca)
    {
        banderaInicioPlaca = false;
    }
    else
    {
        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED && contador < 10000)
        {
            contador++;
            delay(1); // Retardo entre cada intento de conexión
        }
    }
}
// ****************************************************************************************
void enviarMensaje(String mensaje)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        // Datos a enviar
        String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(mensaje);
        HTTPClient http;
        http.begin(url); // Establecer comunicación con API
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        // Enviar petición HTTP de tipo POST
        int httpResponseCode = http.POST(url);
        Serial.println(httpResponseCode);
        if (httpResponseCode != 200)
        {
            // almacenarAlertaFallida();
        }

        // Liberar recursos
        http.end();
    }
}
// ****************************************************************************************
String construirURLDatos()
{
    String urlDatos = "temp=" + String(promedioTemperatura) + "&hum=" + String(promedioHumedad) + "&date=" + date + "&timestamp=" + timestamp;
    return urlDatos;
}
// ****************************************************************************************
void transmitirDatos()
{
    String data = construirURLDatos(); // URL para enviar los datos al servidor

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("Mandando datos");
        HTTPClient https;                                                     // Instancia de cliente HTTPS
        https.begin(serverURL);                                               // Establecer comunicación con servidor
        https.addHeader("Content-Type", "application/x-www-form-urlencoded"); // Cabecera de la petición

        int httpResponseCode = https.POST(data); // Enviar petición HTTPS de tipo POST
        if (httpResponseCode != 200)
        {
            // almacenarTransmisionFallida(data);
        }
        https.end(); // Liberar recursos

        esperarSiguienteCiclo();
    }
    else
    {
        // almacenarTransmisionFallida(data);
        esperarSiguienteCiclo();
    }
}
// ****************************************************************************************