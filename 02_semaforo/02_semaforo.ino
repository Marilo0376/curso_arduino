#define PIN_ROJO 12
#define PIN_AZUL 13
#define PIN_VERDE 14


void setup() {
  pinMode(PIN_ROJO, OUTPUT);
  pinMode(PIN_AZUL, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
}

void loop() { 
  //ROJO encendido
  digitalWrite(PIN_ROJO, HIGH);
  digitalWrite(PIN_AZUL, LOW);
  digitalWrite(PIN_VERDE, LOW);
  delay(500);
  //AZUL encendido
  digitalWrite(PIN_ROJO, LOW);
  digitalWrite(PIN_AZUL, HIGH);
  digitalWrite(PIN_VERDE, LOW);
  delay(500);
  //VERDE encendido
  digitalWrite(PIN_ROJO, LOW);
  digitalWrite(PIN_AZUL, LOW);
  digitalWrite(PIN_VERDE, HIGH);
  delay(500);
  
}
