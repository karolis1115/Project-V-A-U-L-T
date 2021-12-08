#include "global.h" //global header file for global variables and so on (arduino.h and other libraries are included in global.h)
#include "header.h" //header flie for funtion prototypes

// variables
#define time1 300
unsigned long Previousmillis = 0;

void setup()
{
  // attach the servo that's named lock to pin 9(servo)
  lock.attach(servo);

  // generates a seed from the given value that is used in the random() function
  randomSeed(analogRead(A5));

  Serial.begin(9600);

  for (int i = 5; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(rotaryButton, INPUT_PULLUP);

  // interrupts for Rotary enoder
  attachInterrupt(0, encoderChange, CHANGE);
  attachInterrupt(1, encoderChange, CHANGE);
}
int num1, num2, num3, num4;
int dec;
void loop()
{
  // basically does the same as the delay() function but doesn't stop executing everything else.
  // unsigned long Currentmillis = millis();
  // if ((unsigned long)(Currentmillis - Previousmillis) >= time1)
  //{
  // generateRandomNumber(num1, num2, num3, num4);
  // Previousmillis = Currentmillis;
  //}
  countDigits(dec);
  rotaryServo(dec);
  rotaryBuzz(dec);
  selectDisplay(num1, num2, num3, num4);
  displayNumber(num1, num2, num3, num4);
}
