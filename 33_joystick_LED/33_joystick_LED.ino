#define PIN_X 13
#define PIN_Y 12
#define PIN_SW 14

#define NORTE 4
#define SUR 15
#define ESTE 19
#define OESTE 21

int cero_x = 1922;
int cero_y = 1813;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);
  pinMode(PIN_SW, INPUT_PULLUP);

  pinMode(NORTE, OUTPUT);
  pinMode(SUR, OUTPUT);
  pinMode(ESTE, OUTPUT);
  pinMode(OESTE, OUTPUT);
}

void loop() {
  int valor_x = analogRead(PIN_X);
  int valor_y = analogRead(PIN_Y);
  int valor_sw = digitalRead(PIN_SW);

  if (valor_x - cero_x > 10){ //derecha
    Serial.println("Derecha: " + String(valor_x - cero_x));
    onOffLed(ESTE, HIGH);
  }

  if(valor_x - cero_x < -10){ //izquierda
    Serial.println("Izquierda: " + String(valor_x - cero_x));
    onOffLed(OESTE, HIGH);
  }
  if ( valor_y - cero_y > 10 ){ // abajo
    Serial.println("Abajo: " + String(valor_y - cero_y));
    onOffLed(SUR, HIGH);
  }

  if(valor_y - cero_y < -10){ //arriba
    Serial.println("Arriba: " + String(valor_y - cero_y));
    onOffLed(NORTE, HIGH);
  }
  delay(100);
}

void onOffLed(int led, int valor){
  digitalWrite(NORTE, LOW);
  digitalWrite(SUR, LOW);
  digitalWrite(ESTE, LOW);
  digitalWrite(OESTE, LOW); 

  digitalWrite(led, valor);
}
