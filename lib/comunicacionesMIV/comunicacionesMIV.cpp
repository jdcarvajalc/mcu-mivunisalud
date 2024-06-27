// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "comunicacionesMIV.h"
#include "almacenamientoMIV.h"
#include "configMIV.h"
// ****************************************************************************************
// Definición y/o invocación de variables, constantes y objetos
boolean banderaInicioPlaca;
// ****************************************************************************************
void conectarWifi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
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
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
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
    // Datos a enviar
    String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(mensaje);

    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.begin(url); // Establecer comunicación con API
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        // Enviar petición HTTP de tipo POST
        int httpResponseCode = http.POST(url);
        if (httpResponseCode != 200)
        {
            almacenarAlertaFallida(url);
        }

        // Liberar recursos
        http.end();
    }
    else
    {
        almacenarAlertaFallida(url);
    }
}
// ****************************************************************************************
String construirURLDatos()
{
    String urlDatos = "area=" + String(identificadorArea) + "&temp=" + String(promedioTemperatura) + "&hum=" + String(promedioHumedad) + "&date=" + date + "&timestamp=" + timestamp;
    return urlDatos;
}
// ****************************************************************************************
void transmitirDatos()
{
    String data = construirURLDatos(); // URL para enviar los datos al servidor

    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient https;                                                     // Instancia de cliente HTTPS
        https.begin(WEB_APP_URL);                                             // Establecer comunicación con servidor
        https.addHeader("Content-Type", "application/x-www-form-urlencoded"); // Cabecera de la petición

        int httpResponseCode = https.POST(data); // Enviar petición HTTPS de tipo POST
        if (httpResponseCode != 200)
        {
            almacenarTransmisionFallida(data);
        }
        https.end(); // Liberar recursos

        esperarSiguienteCiclo();
    }
    else
    {
        almacenarTransmisionFallida(data);
        esperarSiguienteCiclo();
    }
}
// ****************************************************************************************