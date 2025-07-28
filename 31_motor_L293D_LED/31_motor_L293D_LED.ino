#define VELOCIDAD 14
#define DIRPIN_1 12
#define DIRPIN_2 13
#define PIN_VERDE 15
#define PIN_ROJO 4
#define PIN_AZUL 5

void setup() {
  Serial.begin(115200);

  pinMode(VELOCIDAD, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
  pinMode(PIN_ROJO, OUTPUT);
  pinMode(PIN_AZUL, OUTPUT);

}

void loop() {
//digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
  Serial.println("Girando en una dirección");
  analogWrite(VELOCIDAD, 90);
  digitalWrite(DIRPIN_1, 0);
  digitalWrite(DIRPIN_2, 1);
  digitalWrite(PIN_ROJO, LOW);
  digitalWrite(PIN_AZUL, LOW);
  digitalWrite(PIN_VERDE, HIGH);
  delay(5000);



  digitalWrite(VELOCIDAD, LOW); // Apagamos el motor
  digitalWrite(PIN_ROJO, HIGH);
  digitalWrite(PIN_AZUL, LOW);
  digitalWrite(PIN_VERDE, LOW);
  delay(2000);
  
//digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
  Serial.println("Girando en la otra dirección");
  analogWrite(VELOCIDAD, 90);
  digitalWrite(DIRPIN_1, 1);
  digitalWrite(DIRPIN_2, 0);
  digitalWrite(PIN_ROJO, LOW);
  digitalWrite(PIN_AZUL, HIGH);
  digitalWrite(PIN_VERDE, LOW);
  delay(5000);

}

case cambioEstado