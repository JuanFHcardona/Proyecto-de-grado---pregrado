#include <Wire.h>
#include <MechaQMC5883.h>

MechaQMC5883 qmc;
float inicio;
float tiempo;

void setup() {
  Wire.begin(D4, D1); //Wire.begin(int sda, int scl), esto quiere decir que estamos usando el D2 como sda y el D1 como scl
  Serial.begin(9600);
  qmc.init();
  inicio=millis(); //Permite realizar tomas de datos por un periodo determinado de tiempo
  tiempo=0; //Tiempo transcurrido desde inicio de toma de datos
  qmc.setMode(Mode_Continuous,ODR_200Hz,RNG_2G,OSR_512);
}

void loop() {
  tiempo=millis()-inicio;
  if (tiempo>=0000){
  int x, y, z;
  int azimuth;
  //float azimuth; //is supporting float too
  qmc.read(&x, &y, &z,&azimuth);
  //azimuth = qmc.azimuth(&y,&x);//you can get custom azimuth
  //Serial.print("x: ");
  //Serial.print(x);
  //Serial.print(" y: ");
  //Serial.print(y);
  //Serial.print(" z: ");
  //Serial.print(z);
  Serial.print(" : ");
  Serial.print(azimuth);
  Serial.println();
  delay(100);
  }
}
