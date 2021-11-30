#ifndef GLOBAL_H
#define GLOBAL_H

// libraires
#include <Arduino.h>
#include <EEPROM.h>
//#include <neotimer.h>

// Pin Definitions:
#define servo 6
#define speaker 5
#define redLed 0
#define greenLed 1

// rotary encoder
#define DT 2  // Interrupt pin
#define CLK 3 // Interrupt pin

// Shift register
#define latchClock 8
#define registerClock 7
#define data 9

// 7-seg digit common anodes || cathodes
#define display1En 13
#define display2En 12
#define display3En 11
#define display4En 10

// 3 input accelerometer
#define accX A1
#define accY A2
#define accZ A3

#endif