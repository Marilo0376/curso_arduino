#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13
#define SCL 14
#define ADDR 0x27 // la otra es 0x3F

LiquidCrystal_I2C lcd(ADDR,16,2);

void setup() {
  Wire.begin(SDA,SCL);
  //Wire.beginTransmission(ADDR);

  lcd.init();
  lcd.noBacklight();
  delay(1000);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hola Mundo");
  lcd.setCursor(0, 1); //ésto es columna 0, fila 1
  lcd.print("Bienvenidos...");


}

void loop() {
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);

}
