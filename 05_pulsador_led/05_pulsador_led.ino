#define PULSADOR 13
#define LED 4

int valorBoton = LOW;
int estado = LOW;

void setup() {
  pinMode(PULSADOR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  valorBoton = digitalRead(PULSADOR);

  if(valorBoton == LOW){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  /*
  if(valorBoton == LOW){
    estado = !estado;
    digitalWrite(LED, estado);
  }
  */

   delay(100);
}
