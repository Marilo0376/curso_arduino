#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define DHTPIN 13
#define DHTTYPE DHT11

DHT sensor(DHTPIN,DHT11);

float temp = 0.0; // en programación los decimales siempre se ponen con .
float hum = 0.0;

//conexión a internet

WiFiClient clienteWiFi;
HTTPClient http;

char* servidor = "http://192.168.0.55:5000/datos"; //este número es la dirección IP de nuestro ordenador y el 5000 es el puerto desde el q nos conectamos

// datos de la conexión WIFI
char* ssid = "Aula 1";
char* pwd = "Horus.2025";



void setup() {
  Serial.begin(115200);
  sensor.begin();

// WIFI
WiFi.begin(ssid,pwd);
while(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
Serial.println("Conectado a la IP: ");
Serial.println(WiFi.localIP());
}


void loop() {

  temp = sensor.readTemperature();
  hum = sensor.readHumidity();

  postData(temp, hum, "Marilo local");
  Serial.println("Temp: " + String(temp));
  Serial.println("Hum: " + String(hum));

  delay(5000);
}

void postData(float t, float h, String per){
  String parametros = "temp=" + String(t) + "&hum=" + String(h) + "&persona=" + per; //cadena con POST
  int httpCode;
  String payload;

  if(WiFi.status() == WL_CONNECTED){
    http.begin(clienteWiFi,servidor);
    http.addHeader("Content-Type","application/x-www-form-urlencoded");
    httpCode = http.POST(parametros);
    payload = http.getString();

    Serial.print("HTTP Code: ");
    Serial.println(httpCode);
    Serial.print("Mensaje: ");
    Serial.println(payload);

  }

}
