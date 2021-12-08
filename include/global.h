#ifndef GLOBAL_H
#define GLOBAL_H

//Global variables and stuff that should be included by all of the .cpp files

// libraires
#include <Arduino.h> //the main Arduino library
#include <EEPROM.h>  //the library used for eeprom read/write
#include <wire.h> //the library used for interfacing wit i2c devices (this library is usually used along side other libraries)
#include <hd44780.h> //library for i2c LCD display
#include <GY521.h> //Library for The GY521 IMU(gyro,accelerometer,temp sensor)
#include <Rotary.h>// A great library to drive a rotary encoder, Takes away all of the headace.
#include <Servo.h> // The library used to control the servo
//#include <neotimer.h> //non blockig timer library (may or may not be used)

// Pin Definitions:
#define servo 6
#define speaker 5
#define redLed 0
#define greenLed 1
#define rotaryButton 4

// rotary encoder
#define A 2  // Interrupt pin
#define B 3 // Interrupt pin

// Shift register
#define latchClock 8
#define registerClock 7
#define data 9

// 7-seg digit common anodes || cathodes
#define display1En 13
#define display2En 12
#define display3En 11
#define display4En 10

//variables (to use global variables "extern" needs to be written before the datatype)
extern Servo lock;
extern int count;
#endif
