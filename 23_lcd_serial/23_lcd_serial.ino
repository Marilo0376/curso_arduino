#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

//Pines y configuración
#define SDA 13
#define SCL 14
#define ADDR 0x27 // la otra es 0x3F
#define DHTPIN 15 // PIN  del DHT22
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(ADDR,16,2);

void setup() {
  Serial.begin(115200);

  Wire.begin(SDA,SCL);
  lcd.init();
  lcd.clear();
  lcd.backlight();

  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  lcd.clear();
  
  
  //Linea 1 : Temperatura
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1); //Un decimal
  lcd.write(byte(223)); // Símbolo de grados º
  lcd.print("C");

  //Linea 2: Humedad
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h, 0); // Sin decimales
  lcd.print("%");

delay(2000); // Espera entre lecturas
  }
 

