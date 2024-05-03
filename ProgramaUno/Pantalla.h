/*#include "Costantes.h"

#define SCL_Pin A5  //set a pin of clock to A5
#define SDA_Pin A4  //set a data pin to A4

//this function is used for the display of dot matrix
void matrix_display(unsigned char matrix_value[]) {
  IIC_start();     //use the function to start transmitting data
  IIC_send(0xc0);  //select an address

  for (int i = 0; i < 16; i++)  //image data have 16 characters
  {
    IIC_send(matrix_value[i]);  //data to transmit pictures
  }

  IIC_end();  //end the data transmission of pictures

  IIC_start();
  IIC_send(0x8A);  //show control and select pulse width 4/16
  IIC_end();
}

//the condition that data starts transmitting
void IIC_start() {
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}

//the sign that transmission of data ends
void IIC_end() {
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}

//transmit data
void IIC_send(unsigned char send_data) {
  for (byte mask = 0x01; mask != 0; mask <<= 1)  //each character has 8 digits, which is detected one by one
  {
    if (send_data & mask) {  //set high or low levels in light of each bit(0 or 1)
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH);  //pull up the clock pin SCL_Pin to end the transmission of data
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW);  //pull down the clock pin SCL_Pin to change signals of SDA
  }
}
//******************************************************
*/

#ifndef Pantalla_h
#define Pantalla_h

#include "Arduino.h"

#define SCL_Pin A5  //set a pin of clock to A5
#define SDA_Pin A4  //set a data pin to A4

unsigned char smile[] = { 0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00 };
const char smile2[] = { 0x00, 0x00, 0x00, 0x00, 0x40, 0x8c, 0x8c, 0x80, 0x80, 0x80, 0x8c, 0x8c, 0x40, 0x00, 0x00, 0x00 };
//const char Stop[] = { 0x00, 0x00, 0x4c, 0x92, 0x92, 0x64, 0x00, 0x00, 0x00, 0x02, 0x02, 0xfe, 0x02, 0x02, 0x00, 0x00 };
const char Clear[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const char Ini[] = { 0x42, 0x7e, 0x7e, 0x42, 0x00, 0x7e, 0x06, 0x0c, 0x30, 0x7e, 0x00, 0x00, 0x42, 0x7e, 0x7e, 0x42 };
const char Linea[] = { 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18 };
const char Stop[] = { 0x2E, 0x2A, 0x3A, 0x00, 0x02, 0x3E, 0x02, 0x00, 0x3E, 0x22, 0x3E, 0x00, 0x3E, 0x0A, 0x0E, 0x00 };

//const char Izquierda[] = { 0x12, 0x1e, 0x12, 0x00, 0x12, 0x1a, 0x16, 0x00, 0x0c, 0x12, 0x1a, 0x1c, 0x20, 0x00, 0x00, 0x00 };
const char Izquierda[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x00 };
//const char Derecha[] = { 0x00, 0x7c, 0x44, 0x38, 0x00, 0x38, 0x44, 0x44, 0x00, 0x7c, 0x10, 0x7c, 0x00, 0x00, 0x00, 0x00 };
const char Derecha[] = { 0x00, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
class Pantalla {
public:
  Pantalla();          // Constructor
  void Inicializar();  // Inicializar la pantalla
  void MostrarSmile();
  void MostrarSmile2();
  void MostrarLinea();
  void MostrarStop();
  void MostrarIzquierda();
  void MostrarDerecha();
  void LimpiarPantalla();
  // Otras funciones para mostrar contenido en la pantalla

private:

  void IIC_start();
  void IIC_send(unsigned char data);
  void IIC_end();
  void matrix_display(unsigned char matrix_value[]);
};

#endif

Pantalla::Pantalla() {
  // Constructor
}

void Pantalla::Inicializar() {
  // Inicializa la pantalla, configura pines, etc.
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
}

void Pantalla::MostrarSmile() {
  // Muestra el smile en la pantalla
  matrix_display(smile);
}

void Pantalla::MostrarSmile2() {
  // Muestra el smile2 en la pantalla
  matrix_display(smile2);
}

void Pantalla::MostrarLinea() {
  // Muestra el smile2 en la pantalla
  matrix_display(Linea);
}

void Pantalla::MostrarStop() {
  // Muestra el smile2 en la pantalla
  matrix_display(Stop);
}

void Pantalla::MostrarIzquierda() {
  // Muestra el smile2 en la pantalla
  matrix_display(Izquierda);
}

void Pantalla::MostrarDerecha() {
  // Muestra el smile2 en la pantalla
  matrix_display(Derecha);
}

void Pantalla::LimpiarPantalla() {
  // Muestra el smile2 en la pantalla
  matrix_display(Clear);
}

// Implementa otras funciones aquí
//the condition that data starts transmitting
void Pantalla::IIC_start() {
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}

//the sign that transmission of data ends
void Pantalla::IIC_end() {
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}

//transmit data
void Pantalla::IIC_send(unsigned char send_data) {
  for (byte mask = 0x01; mask != 0; mask <<= 1)  //each character has 8 digits, which is detected one by one
  {
    if (send_data & mask) {  //set high or low levels in light of each bit(0 or 1)
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH);  //pull up the clock pin SCL_Pin to end the transmission of data
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW);  //pull down the clock pin SCL_Pin to change signals of SDA
  }
}

void Pantalla::matrix_display(unsigned char matrix_value[]) {
  IIC_start();     //use the function to start transmitting data
  IIC_send(0xc0);  //select an address

  for (int i = 0; i < 16; i++)  //image data have 16 characters
  {
    IIC_send(matrix_value[i]);  //data to transmit pictures
  }

  IIC_end();  //end the data transmission of pictures

  IIC_start();
  IIC_send(0x8A);  //show control and select pulse width 4/16
  IIC_end();
}
