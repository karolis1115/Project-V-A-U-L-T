#include "global.h" //global header file for global variables and so on (arduino.h and other libraries are included in global.h)
#include "header.h" //header flie for funtion prototypes

// variables
#define time1 300
unsigned long Previousmillis = 0;

void setup()
{
  Serial.begin(9600);
  for (int i = 4; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  
  // interrupts for Rotary enoder
  attachInterrupt(0, encoderChange, CHANGE);
  attachInterrupt(1, encoderChange, CHANGE);
}

void loop()
{
  int num1, num2, num3, num4;
  unsigned long Currentmillis = millis();
  int min = 0;
  int max = 10;
  //basically does the same as the delay() function but doesn't stop executing everything else.
   if ((unsigned long)(Currentmillis - Previousmillis) >= time1)
  {
   //generateRandomNumber(min, max, num1, num2, num3, num4);
   Previousmillis = Currentmillis;
  }
  countDigits(num1);
  displayNumber(num1, num1, num1, num1);
}
