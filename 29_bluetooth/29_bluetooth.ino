#include <BluetoothSerial.h>

BluetoothSerial serialBT;

void setup() {
  Serial.begin(115200);
  serialBT.begin("Marilo_BT");
  Serial.println("Dispositivo listo para emparejarse");
  
}

void loop() {
  if (Serial.available()) {
    serialBT.write(Serial.read()); //ésto lee lo que metamos por el monitor series
  }
  if (serialBT.available()) {
    Serial.write(serialBT.read());
  }

}
