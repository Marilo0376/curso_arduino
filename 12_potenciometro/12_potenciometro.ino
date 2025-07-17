#define LED 25
#define POT 4
#define POT2 5
#define ZUMBADOR 12

int valorPot = 0;
int valorLed = 0;
int valorPotZ = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);
  pinMode(POT2, INPUT);
  pinMode(ZUMBADOR, OUTPUT);

}


void loop() {
  // 0  4096
  valorPot = analogRead(POT);
  valorPotZ = analogRead(POT2);

  valorLed = map(valorPot, 0, 4096, 0, 255);

  analogWrite(LED, valorPot);

  digitalWrite(ZUMBADOR, HIGH);
  delay(valorPotZ);

  digitalWrite(ZUMBADOR, LOW);
  delay(valorPotZ);

  Serial.println("Led: " + String(valorLed)+ "POT: "+String(valorPot));
  Serial.println("Frecuencia: "+String(valorPotZ)+"Hz");

}
