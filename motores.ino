/******************
*  Pines motor A (derecho)
*****************/

const int PINR = D2;

/******************
*  Pines motor B (izquierdo)
*****************/

const int PINL = D5;

/******************
*  Velocidades PWM
*****************/

int speedR = 96;
int speedL = 84;

void setup() {

  pinMode(PINR, OUTPUT);
  pinMode(PINL, OUTPUT);

}

void loop() {

  analogWrite(PINR, speedR);
  analogWrite(PINL, speedL);
  
}
