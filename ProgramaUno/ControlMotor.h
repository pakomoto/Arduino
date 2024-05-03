#ifndef ControlMotor_h
#define ControlMotor_h

#include "Arduino.h"


#define ML_Ctrl 4  //Define the direction control pin of the left motor
#define ML_PWM 6   //Define the PWM control pin of the left motor
#define MR_Ctrl 2  //Define the direction control pin of the right motor
#define MR_PWM 5   //Define the PWM control pin of the right motor

class ControlMotor {
public:
  ControlMotor();      // Constructor
  void Inicializar();  // Inicializar el Sensor Ultrasonico
  void Avanzar();
  void Retroceder();
  void Parar();
  void Izquierda();
  void Derecha();
  void RetrocederPoco();

private:
};

#endif

ControlMotor::ControlMotor() {
}

void ControlMotor::Inicializar() {
  pinMode(ML_Ctrl, OUTPUT);  //Define the direction control pin of the left motor as OUTPUT
  pinMode(ML_PWM, OUTPUT);   //Define the PWM control pin of the left motor as OUTPUT
  pinMode(MR_Ctrl, OUTPUT);  //Define the direction control pin of the right motor as OUTPUT
  pinMode(MR_PWM, OUTPUT);   //Define the PWM control pin of the right motor as OUTPUT
}

void ControlMotor::Avanzar() {
  //front
  digitalWrite(ML_Ctrl, HIGH); //Set direction control speed of the left motor to HIGH
  analogWrite(ML_PWM, 55); //PWM control speed of the left motor is 200
  digitalWrite(MR_Ctrl, HIGH); //Set direction control speed of the right motor to HIGH
  analogWrite(MR_PWM, 55); //PWM control speed of the right motor is 200
  delay(250);//delay in 1/2s
}

void ControlMotor::RetrocederPoco() {
  digitalWrite(ML_Ctrl, LOW); //Set direction control speed of the left motor to LOW
  analogWrite(ML_PWM, 200); //PWM control speed of the left motor is 200
  digitalWrite(MR_Ctrl, LOW); //Set direction control speed of the right motor to LOW
  analogWrite(MR_PWM, 200); //PWM control speed of the right motor is 200
  delay(100);//delay in 1/2s
  this->Parar();
}

void ControlMotor::Retroceder() {
  digitalWrite(ML_Ctrl, LOW); //Set direction control speed of the left motor to LOW
  analogWrite(ML_PWM, 200); //PWM control speed of the left motor is 200
  digitalWrite(MR_Ctrl, LOW); //Set direction control speed of the right motor to LOW
  analogWrite(MR_PWM, 200); //PWM control speed of the right motor is 200
  delay(500);//delay in 1/2s
  this->Parar();
}

void ControlMotor::Parar() {
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 0); //PWM control speed of the left motor is 0
  digitalWrite(MR_Ctrl, LOW);
  analogWrite(MR_PWM, 0); //PWM control speed of the right motor is 0
  delay(500);//delay in 1/2s
}

void ControlMotor::Izquierda() {
  digitalWrite(ML_Ctrl, LOW); //Set direction control speed of the left motor to LOW
  analogWrite(ML_PWM, 200); //PWM control speed of the left motor is 200
  digitalWrite(MR_Ctrl, HIGH); //Set direction control speed of the right motor to HIGH
  analogWrite(MR_PWM, 55); //PWM control speed of the right motor is 200
  delay(250);//delay in 1/2s
  this->Parar();
}

void ControlMotor::Derecha() {
  digitalWrite(ML_Ctrl, HIGH); //Set direction control speed of the left motor to HIGH
  analogWrite(ML_PWM, 55); //PWM control speed of the left motor is 200
  digitalWrite(MR_Ctrl, LOW); //Set direction control speed of the right motor to LOW
  analogWrite(MR_PWM, 200); //PWM control speed of the right motor is 200
  delay(250);//delay in 1/2s
  this->Parar();
}
