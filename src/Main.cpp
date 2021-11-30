#include "global.h" //arduino.h and other libraries are included in global.h
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
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
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
  // encoderRead(num1,num2,num3);
  // ReadAcc7_seg(num1, num2, num3);
  displayNumber(num1, num2, num3, num4);
}
