int dia= 7;
String nombreDia = "";
void setup() {

  Serial.begin(115200);
  delay(500);
  
  // put your setup code here, to run once:
  switch (dia) {
  case 1: 
  nombreDia = "El dia es Lunes";
  break;
  case 2:
  nombreDia = "El dia es Martes";
  break;
   case 3: 
  nombreDia = "El dia es Miercoles";
  break;
   case 4: 
  nombreDia = "El dia es Jueves";
  break;
   case 5: 
  nombreDia = "El dia es Viernes";
  break;
   case 6: 
  nombreDia = "El dia es Sabado";
  break;
   case 7: 
  nombreDia = "El dia es Domingo";
  break;
  default:
  nombreDia="NO es ningun dia de la semana";
  break;
  }

  Serial.println(nombreDia);

//05_switch_2 proyecto día 15.07.25

int nota = 7;
String calif = "";
switch (nota) {
  case 1:
  case 2:
  case 3:
  case 4:
  calif = "SUSPENSO";
  break;
  case 5 ... 6: // es lo mismo que case 1, case 2, case 3 pero para no repetirnos tanto
  calif = "APROBADO";
  break;
  case 7 ... 8:
  calif = "NOTABLE";
  break;
  default:
  calif = "SOBRESALIENTE";
  break;
}
Serial.println("La calificación es " + calif);
}

void loop(){

}


