/*
Fundación Kinal
Centro Educativo Técnico Laboral Kinal 
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de 
Computadoras I
Nombre: Jose Sebastian Bocaletti Aguilar
Carné: 2022235
*/

#define trighhh 4 
#define eco 5
#define buzzer 6

int duracion; 
int Do = 261;
int Re = 294;
int Mi = 329;
int Fa = 349;
int Sol = 392;
int La = 440;
int Si = 494;
int DoS = 523;

void setup() {
  pinMode(trighhh, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  C_Distancia(duracion);
  cancion();
}

int C_Distancia(int num1) {
  int distancia;

  digitalWrite(trighhh, HIGH);
  delayMicroseconds(30);
  digitalWrite(trighhh, LOW);  
  num1 = pulseIn(eco, HIGH);
  distancia = num1 / 58.7;
  Serial.println(distancia);
  delay(100);

  return distancia;
}

void nota_buzzer(int num1) {
  tone(buzzer, num1);
}

void cancion(void) {
  int nota = C_Distancia(duracion);
  if (nota > 1 && nota < 4) {
    nota_buzzer(Do);
  }
  else if (nota >= 4  && nota < 8) {
    nota_buzzer(Re);
  }
  else if (nota >= 8 && nota < 12) {
    nota_buzzer(Mi);
  }
  else if (nota >= 12 && nota < 16) {
    nota_buzzer(Fa);
  }
  else if (nota >= 16  && nota < 20) {
    nota_buzzer(Sol);
  }
  else if (nota >= 20 && nota < 24) {
    nota_buzzer(La);
  }
  else if (nota >= 24 && nota < 28) {
    nota_buzzer(Si);
  }
  else if (nota >= 28 && nota < 32) {
    nota_buzzer(DoS);
  }
  else {
    noTone(buzzer);
  }
}
