// ****************************************************************************************
// Archivo de declaración de variables, constantes y objetos
#include "sensorMIV.h"
// ****************************************************************************************
Adafruit_SHT31 sht31 = Adafruit_SHT31();
float promedioTemperatura = 0.0;
float promedioHumedad = 0.0;
// ****************************************************************************************
void iniciarSensor(){
  while (!sht31.begin(0x44)) {   
    delay(1);
  }
}
// ****************************************************************************************
float leerTemperatura() {
  float temperature;
  return temperature = sht31.readTemperature();
}
// ****************************************************************************************
float leerHumedad() {
  float humidity;
  return humidity = sht31.readHumidity();
}
// ****************************************************************************************
float calcularPromedio(float suma, float cantidadNumeros){
  return  suma/cantidadNumeros;
}
// ****************************************************************************************
void capturarYGestionarDatos(){
  promedioTemperatura = 0.0;
  promedioHumedad = 0.0;
  float sumaTemp = 0.0, sumaHum = 0.0;
  int contadorLecturas = 101;

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

  // Calcular promedios
  promedioTemperatura = calcularPromedio(sumaTemp, contadorLecturas);
  promedioHumedad = calcularPromedio(sumaHum, contadorLecturas);
}
// ****************************************************************************************