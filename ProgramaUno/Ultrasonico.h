#ifndef Ultrasonico_h
#define Ultrasonico_h

#include "Arduino.h"


class SensorUltrasonico {
public:
  SensorUltrasonico();  // Constructor
  void Inicializar();   // Inicializar el Sensor Ultrasonico
  long CompruebaDistancia();

private:
  int trigPin = 12;  // Pin Trig attaches to 12
  int echoPin = 13;  //Pin Echo attaches to 13
  long duration, inches;
};

#endif

SensorUltrasonico::SensorUltrasonico() {
  // Constructor
  this->duration = 0;
}

void SensorUltrasonico::Inicializar() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long SensorUltrasonico::CompruebaDistancia() {
  long cm = 0;
  //Pre-given a short low pulse to ensure a clean high pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  //At least give 10us high level trigger
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // The time in high level equals the time gap between the transmission and the return of the ultrasonic sound
  this->duration = pulseIn(echoPin, HIGH);
  // Translate into distance
  cm = (duration / 2) / 29.1;    // convert to centimeters
  this->inches = (duration / 2) / 74;  //  Convert to inch
  return cm;
}