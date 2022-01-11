#include "global.h" //global header file for global variables and so on (arduino.h and other libraries are included in global.h)
#include "header.h" //header flie for funtion prototypes

// variables
#define time1 300
unsigned long Previousmillis = 0;
int choice;       // Choice made by the user to use rng or own code
int PWinput;      // password input by the user
int attempts = 1; // 3 attempts allowwed for the user
int tnum1 = 0, tnum2 = 0, tnum3 = 0, tnum4 = 0;
int dec;
int firstDigit = 0;

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
  pinMode(doorSensor, INPUT_PULLUP);

  // interrupts for Rotary enoder
  attachInterrupt(digitalPinToInterrupt(2), encoderChange, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), encoderChange, CHANGE);
}

void loop()
{
  bool correct = false;
  bool done = false;
  bool entered = false;
  int num1, num2, num3, num4;
  if (EEPROM.read(0) == 0 && EEPROM.read(1) == 0 && EEPROM.read(2) == 0 && EEPROM.read(3) == 0)
  {
    int firstDigit = 0;
    // generateRandomNumber(num1, num2, num3, num4);
    while (choice < 4)
    {
      displayNumber(num1, num2, num3, num4);
      selectDisplay(num1, num2, num3, num4, choice);
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      if (choice < 3)
      {
        firstDigit = num1;
      }
    }
    EEPROM.write(0, firstDigit);
    EEPROM.write(1, num2);
    EEPROM.write(2, num3);
    EEPROM.write(3, num4);
    done = true;
  }

  while (!correct)
  {
    while (!entered && choice < 4)
    {
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      displayNumber(tnum1, tnum2, tnum3, tnum4);
      selectDisplay(tnum1, tnum2, tnum3, tnum4, choice);
      if (choice < 3)
      {
        firstDigit = tnum1;
      }
    }

    if (firstDigit == EEPROM.read(0) && tnum2 == EEPROM.read(1) && tnum3 == EEPROM.read(2) && tnum4 == EEPROM.read(3))
    {
      correct = true;
    }

    else
    {
      correct = false;
      digitalWrite(redLed, HIGH);
      choice = 0;
      entered = false;
    }
  }
  while (correct)
  {
    digitalWrite(greenLed, HIGH);
    unlockTone();
    unlockVault();
    displayNumber(firstDigit, tnum2, tnum3, tnum4);

    if (digitalRead(doorSensor) == LOW)
    {
      correct = false;
      firstDigit = 0;
      tnum2 = 0;
      tnum3 = 0;
      tnum4 = 0;
    }
  }
}

// basically does the same as the delay() function but doesn't stop executing everything else.
// unsigned long Currentmillis = millis();
// if ((unsigned long)(Currentmillis - Previousmillis) >= time1)
//{

// Generates a random number for each digit
//  generateRandomNumber(num1, num2, num3, num4);
//  Previousmillis = Currentmillis;
// }
