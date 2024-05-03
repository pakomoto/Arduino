#ifndef ControlServo_h
#define ControlServo_h

#include "Arduino.h"

#define servoPin 10  //The pin of servo

class ControlServo {
public:
  ControlServo();      // Constructor
  void Inicializar();  // Inicializar el Sensor Ultrasonico
  void Izquierda();
  void Derecha();
  void Centro();

private:
  void Procedure(int myangle);
  void Comprobacion();

  int pos;         //The variable of servo’s angle
  int pulsewidth;  //The variable of servo’s pulse width
  int posicionUltima = 0;
  int esperaMovimiento = 1;
};

#endif

ControlServo::ControlServo() {
}

void ControlServo::Inicializar() {
  pinMode(servoPin, OUTPUT);  //Set the pin of servo as output


  this->Comprobacion();
}

void ControlServo::Procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  //Calculate the value of pulse width

  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulsewidth);  //The time in high level represents the pulse width
  digitalWrite(servoPin, LOW);
  delay((20 - pulsewidth / 1000));  //As the cycle is 20ms, the time left is in low level
}

void ControlServo::Comprobacion() {
  this->Izquierda();
  delay(1000);
  this->Derecha();
  delay(1000);
  this->Centro();
  delay(1000);
  this->Izquierda();
  delay(1000);
  this->Centro();
  delay(1000);
}
void ControlServo::Izquierda() {
  for (pos = this->posicionUltima; pos >= 0; pos -= 1) {  // From 1°to 180°
    // in steps of 1 degree
    this->Procedure(pos);  // Rotate to the angle of 'pos'
    delay(this->esperaMovimiento);             //Control the speed of rotation
    //Serial.println(pos);
    this->posicionUltima = pos;
  }

}
void ControlServo::Derecha() {
  for (pos = this->posicionUltima; pos <= 180; pos += 1) {  // From 1°to 180°
    // in steps of 1 degree
    this->Procedure(pos);  // Rotate to the angle of 'pos'
    delay(this->esperaMovimiento);             //Control the speed of rotation
    //Serial.println(pos);
    this->posicionUltima = pos;
  }

}
void ControlServo::Centro() {
  
  if (this->posicionUltima == 180) {
    for (pos = this->posicionUltima; pos >= 90; pos -= 1) {  // From 1°to 180°
      // in steps of 1 degree
      this->Procedure(pos);  // Rotate to the angle of 'pos'
      delay(this->esperaMovimiento);             //Control the speed of rotation
      //Serial.println(pos);
      this->posicionUltima = pos;
    }
  } else {
    for (pos = this->posicionUltima; pos <= 90; pos += 1) {  // From 1°to 180°
      // in steps of 1 degree
      this->Procedure(pos);  // Rotate to the angle of 'pos'
      delay(esperaMovimiento);             //Control the speed of rotation
      //Serial.println(pos);
      this->posicionUltima = pos;
    }
  }

}
