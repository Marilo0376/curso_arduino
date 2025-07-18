
void setup() {
  Serial.begin(115200);
  delay(500);

  //int numero = sumar(3,2);
  //Serial.println(numero);
  int acumulador = 0;
int valores[] = {1,3,4,5,8,12,34};

for(int i = 0; i < 7; i ++){
  acumulador = sumar(acumulador, valores[i]);
}

Serial.print("Total: ");
Serial.println(acumulador);

// - - - - - - - - - - - - - - -

char cadena[] = "Hola Mundo";
int largo = longitudCadena (cadena);
Serial.print("Longitud: ");
Serial.println(largo);


// - - - - - - - - - - - - - - - - - 
char* resultado;
resultado = inversa(cadena);
Serial.print("Original: ");
Serial.println(cadena);
Serial.print("Inversa: ");
Serial.print(resultado);
}

void loop() {

  // put your main code here, to run repeatedly:

}

//FUNCIONES
/*
tipo nombre_funcion(tipo parametro, tipo parametro2,...){

}
int respuesta = nombre_funcion(int parametro, int parametro2, ...){

}*/

// FUNCIÓN QUE SUMA DOS NÚMEROS

int sumar(int primero, int segundo){
  /*
  1. Validar las entradas
  2. Hacer el trabajo
  3. Validar los resultados
  */
  int temp = primero + segundo;
  return temp; 

}

//AHORA VAMOS A HACER UNA FUNCIÓN QUE CALCULE LA LONGITUD DE UNA CADENA DE TEXTO

//1º DEFINIMOS NUESTRA FUNCIÓN

int longitudCadena(char cadena[]){  // esta manera de escribir se llama camelCase y se escribe la 1º palabra entera minúscula y las demás con la primera letra mayúscula
  int i = 0;
  while(cadena[i] != '\0'){
  i++;
  }
  return i;

}      


//AHORA VAMOS A HACER UNA FUNCIÓN QUE NOS CAMBIE EL SENTIDO DE UNA CADENA , x ejemplo: HOLA y cambiamos a ALOH

//1º le damos nombre a nuestra función y la definimos
char* inversa(char* cadena){
  int longitud = longitudCadena(cadena);
  char* temp = new char[longitud + 1]; //memoria dinámica, +1 para '\0'

  for (int i = 0; i < longitud; i++){
    temp[longitud -i -1] = cadena[i];
  }
  temp[longitud] = '\0'; // final de cadena

  return temp; //recuerda liberar con delete [] luego
}










