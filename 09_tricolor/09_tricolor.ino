#define LED_ROJO 15
#define LED_VERDE 13
#define LED_AZUL 12

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
 
}

void loop() {
  /*
  // LED_ROJO
   digitalWrite(LED_ROJO, LOW);
   digitalWrite(LED_VERDE, HIGH);
   digitalWrite(LED_AZUL, HIGH);

   delay(500);

   // LED_VERDE
   digitalWrite(LED_ROJO, HIGH);
   digitalWrite(LED_VERDE, LOW);
   digitalWrite(LED_AZUL, HIGH);

   delay(500);

   //LED_AZUL
   digitalWrite(LED_ROJO, HIGH);
   digitalWrite(LED_VERDE, LOW);
   digitalWrite(LED_AZUL, HIGH);

   delay(500);

// MAGENTA
   digitalWrite(LED_ROJO, LOW);
   digitalWrite(LED_VERDE, HIGH);
   digitalWrite(LED_AZUL, LOW);

   delay(500);

// CIAN
      digitalWrite(LED_ROJO, HIGH);
   digitalWrite(LED_VERDE, LOW);
   digitalWrite(LED_AZUL, LOW);
   
   delay(500)

AMARILLO
   digitalWrite(LED_ROJO, LOW);
   digitalWrite(LED_VERDE, LOW);
   digitalWrite(LED_AZUL, HIGH);
   
   delay(500)

BLANCO
   digitalWrite(LED_ROJO, LOW);
   digitalWrite(LED_VERDE, LOW);
   digitalWrite(LED_AZUL, LOW);
   
   delay(500);

*/

int r = 0;
int g = 0;
int b = 0;

for(;;){
  r = random(0, 255);
  g = random(0, 255);
  b = random(0, 255);

  analogWrite (LED_ROJO, r);
  analogWrite (LED_VERDE, g);
  analogWrite (LED_AZUL, b);

  delay (1000);
}
}
