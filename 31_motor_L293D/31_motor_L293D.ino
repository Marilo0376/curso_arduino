#define VELOCIDAD 14
#define DIRPIN_1 12
#define DIRPIN_2 13

void setup() {
  Serial.begin(115200);

  pinMode(VELOCIDAD, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);

}

void loop() {
//digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
  Serial.println("Girando en una dirección");
  analogWrite(VELOCIDAD, 90);
  digitalWrite(DIRPIN_1, 0);
  digitalWrite(DIRPIN_2, 1);
  delay(500);

  digitalWrite(VELOCIDAD, LOW); // Apagamos el motor
  delay(2000);
  
//digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
  Serial.println("Girando en la otra dirección");
  analogWrite(VELOCIDAD, 90);
  digitalWrite(DIRPIN_1, 1);
  digitalWrite(DIRPIN_2, 0);
  delay(500);

}
