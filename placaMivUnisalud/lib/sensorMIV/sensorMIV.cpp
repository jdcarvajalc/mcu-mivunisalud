// ****************************************************************************************
#include "sensorMIV.h"
// ****************************************************************************************
/**
* @brief Instancia del objeto SHT31.
*/
Adafruit_SHT31 sht31 = Adafruit_SHT31();
// ****************************************************************************************
/**
* @brief Variable de promedio de temperatura
*/
float promedioTemperatura = 0.0;
// ****************************************************************************************
/**
* @brief Variable de promedio de humedad
*/
float promedioHumedad = 0.0;
// ****************************************************************************************
/**
* @brief Lee la temperatura del sensor DHT y la devuelve como un valor de tipo float.
* @return El valor de la temperatura leído.
*/
float leerTemperatura() {
  float temperature;
  return temperature = sht31.readTemperature();
}
// ****************************************************************************************
/**
* @brief Lee la humedad del sensor DHT y la devuelve como un valor de tipo float.
* @return El valor de la humedad leído.
*/
float leerHumedad() {
  float humidity;
  return humidity = sht31.readHumidity();
}
// ****************************************************************************************
/**
* @brief Calcula el promedio de temperatura y humedad a partir de múltiples lecturas
* del sensor y actualiza las variables globales promedioTemperatura y promedioHumedad.
* 
* @param [in] suma Suma del conjunto de números
* @param [in] cantidadNumeros Cantidad de números en el conjunto
* 
* @return El promedio del conjunto de números
*/
float calcularPromedio(float suma, float cantidadNumeros){
  return  suma/cantidadNumeros;
}
// ****************************************************************************************
/**
* @brief Integra las demás funciones para cumplir con los servicios del
* sistema: captura y gestión de datos. 
*/
void capturarYGestionarDatos(){
  promedioTemperatura = 0.0;
  promedioHumedad = 0.0;
  float sumaTemp = 0.0, sumaHum = 0.0;
  int contadorLecturas = 101;
  unsigned long tiempo1, tiempo2, transcurrido;

  tiempo1 = millis();

  // Leer 101 veces la temperatura y humedad
  for( int i = 0; i < contadorLecturas; i++ ){
    float temp = leerTemperatura();
    float hum = leerHumedad();

    // Validar valores nulos y ceros
    if (!isnan(temp) && !isnan(hum) && (temp!=0) && (hum!=0)) {
      sumaTemp += temp;
      sumaHum += hum;
    }
    else{
      i--;
    }   
  }
  tiempo2 = millis();
  // Calcular promedios
  promedioTemperatura = calcularPromedio(sumaTemp, contadorLecturas);
  promedioHumedad = calcularPromedio(sumaHum, contadorLecturas);

  Serial.print("Promedio Temperatura: ");
  Serial.println(promedioTemperatura);
  Serial.print("Promedio Humedad: ");
  Serial.println(promedioHumedad);
  Serial.print("Tiempo  de Captura [ms]: ");
  transcurrido = tiempo2 - tiempo1;
  Serial.println(transcurrido);
}
// ****************************************************************************************