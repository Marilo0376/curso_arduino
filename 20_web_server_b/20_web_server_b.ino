#include <WiFi.h>  //Incluye la libreria necesaria para manejar conexiones WiFi
#include <WebServer.h>

#define LED 2

char* ssid = "Aula 1";
char* pwd = "Horus.2025";

WebServer servidor(80);

//Paginas

String home = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h1>Hola Mundo</h1><h2>Esta es la primera pagina</h2><a href=\"/segunda\">Ir a la segunda página</a><br><a href=\"/led\">Ir a Led</a></body></html>";
String home2 = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Segunda Pagina</title></head><body><h1>Esta es la segunda pagina</h1></body></html>";
String homeLed = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Control de LED Arduino</title><style>body{font-family:Arial,sans-serif;display:flex;justify-content:center;align-items:center;min-height:100vh;margin:0;background-color:#f4f4f4}.container{background-color:#fff;padding:30px;border-radius:8px;box-shadow:0 2px 10px rgba(0,0,0,.1);text-align:center}h1{color:#333;margin-bottom:20px}.button-group{display:flex;justify-content:center;gap:20px;margin-top:20px}.led-button{color:white;padding:15px 30px;text-align:center;text-decoration:none;display:inline-block;font-size:20px;cursor:pointer;border:none;border-radius:5px;transition:background-color .3s ease}.led-button.on{background-color:#4CAF50}.led-button.on:hover{background-color:#45a049}.led-button.off{background-color:#f44336}.led-button.off:hover{background-color:#da190b}</style></head><body><div class=\"container\"><h1>Control de LED</h1><p>Usa los botones para controlar el LED de tu placa Arduino.</p><div class=\"button-group\"><a href=\"/led\" class=\"led-button on\">Encender LED</a><a href=\"/apagar\" class=\"led-button off\">Apagar LED</a></div></div></body></html>";
void setup() {
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);  //Configura el ESP32 como cliente WIFI
  WiFi.begin(ssid, pwd);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a la IP: ");
  Serial.println(WiFi.localIP());

    //solicitudes web
  servidor.on("/", handle_OnConnect); 
  servidor.on("/segunda",handle_OnConnect2); // No está llamando a la funcion, sino que se ejecuta cuando pasa ésto
  servidor.on("/led", handle_Encender);

  servidor.begin();
  Serial.println("Servidor web iniciado");
}

void loop() {
  
  servidor.handleClient(); //Escucha las peticiones de los clientes al servidor
}

//Función de respuesta a las paginas web
void handle_OnConnect(){

  servidor.send(200,"text/html",home); //Esta diciendo que el texto que hay en la variable home va a ser un texto estilo html si esta todo ok
}
void handle_OnConnect2(){

  servidor.send(200,"text/html",home2); //Esta diciendo que el texto que hay en la variable home va a ser un texto estilo html si esta todo ok
}

void handle_Encender(){
  digitalWrite(LED, HIGH);
}

void handle_Apagar(){
  digitalWrite(LED, LOW);
}