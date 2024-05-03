/*
  Keyestudio Mini Tank Robot V3 (Popular Edition)
  lesson 12.1
  Matrix face
  http://www.keyestudio.com
*/
//get the data of smile image from a modulus tool
//#include "Costantes.h"
#include "Pantalla.h"
#include "Ultrasonico.h"
#include "ControlServo.h"
#include "ControlMotor.h"

Pantalla pantalla;  // Crea un objeto Pantalla
SensorUltrasonico Sensor;
ControlServo Servo;
ControlMotor Motor;

int DistanciaStop = 30;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pantalla.MostrarLinea();  // Muestra el smile en la pantalla

  pantalla.Inicializar();
  Sensor.Inicializar();
  Servo.Inicializar();
  Motor.Inicializar();
 
  delay(1000);
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("Setup del programa");  
}
void loop() {
  int distanciaIzquierda = 0;
  int distanciaDerecha = 0;

  if (Sensor.CompruebaDistancia() < DistanciaStop) {
    Motor.Parar();
    pantalla.MostrarStop();
    Motor.RetrocederPoco();

    Servo.Izquierda();
    distanciaIzquierda = Sensor.CompruebaDistancia();
    Servo.Derecha();
    distanciaDerecha = Sensor.CompruebaDistancia();

    if (distanciaIzquierda < distanciaDerecha) {
      pantalla.MostrarIzquierda();
      Motor.Retroceder();
      Motor.Izquierda();
    } else {
      pantalla.MostrarDerecha();
      Motor.Retroceder();
      Motor.Derecha();
    }

    delay(1000);
    Servo.Centro();
  } else {
    pantalla.MostrarSmile2();
    Motor.Avanzar();
  }  
}
