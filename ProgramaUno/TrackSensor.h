#ifndef TrackSensor_h
#define TrackSensor_h

#include "Arduino.h"

#define L_pin  11  //left
#define M_pin  7  //middle
#define R_pin  8  //right


class TrackSensor {
public:
  TrackSensor();  // Constructor
  void Inicializar();   // Inicializar el Sensor Ultrasonico
  void EstadoSensor();
private:
  int L_val, M_val, R_val;
};

#endif

TrackSensor::TrackSensor() {
  // Constructor
  this->duration = 0;
}

void TrackSensor::Inicializar() {
  pinMode(L_pin, INPUT); //Set all pins of the line tracking sensor as input mode
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(MR_Ctrl, OUTPUT);
  pinMode(MR_PWM, OUTPUT);
  
}

void TrackSensor::EstadoSensor()
{
  L_val = digitalRead(L_pin); //Read the value of the left sensor
  M_val = digitalRead(M_pin); //Read the value of the middle sensor
  R_val = digitalRead(R_pin); //Read the value of the right sensor
}
