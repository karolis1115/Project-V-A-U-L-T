#include "global.h" //global header file for global variables and so on (arduino.h and other libraries are included in global.h)
#include "header.h" //header flie for funtion prototypes

// variables
#define time1 300
unsigned long Previousmillis = 0;

void setup()
{
  for (int i = 2; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(DT, INPUT_PULLUP);
  pinMode(CLK, INPUT_PULLUP);
  pinMode(accX, INPUT);
  pinMode(accY, INPUT);
  pinMode(accZ, INPUT);

  // interrupts for Rotary enoder
  attachInterrupt(digitalPinToInterrupt(DT), isrA, RISING);
  attachInterrupt(digitalPinToInterrupt(CLK), isrB, RISING);
}

void loop()
{
  int num1, num2, num3, num4;
  unsigned long Currentmillis = millis();
  int min = 0;
  int max = 10;


   if ((unsigned long)(Currentmillis - Previousmillis) >= time1)
  {
   generateRandomNumber(min, max, num1, num2, num3, num4);
   Previousmillis = Currentmillis;
  }
  //readEncoder(num1);
  //ReadAcc7_seg(num1, num2, num3);
  displayNumber(num1, num2, num3, num4);
}
