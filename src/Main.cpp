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
bool executed =false;
 int incorrect =0;
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
  pinMode(resetButton,INPUT_PULLUP);
  pinMode(bcdBlanking,OUTPUT);
  digitalWrite(bcdBlanking,HIGH);

  // interrupts for Rotary enoder
  attachInterrupt(digitalPinToInterrupt(2), encoderChange, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), encoderChange, CHANGE);
}

void loop()
{
  int num1, num2, num3, num4;
  bool correct = false;
  bool entered = false;
  if (EEPROM.read(0) == 0 && EEPROM.read(1) == 0 && EEPROM.read(2) == 0 && EEPROM.read(3) == 0)
  {
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
  }

  while (!correct)
  {
    executed = false;
    lockVault();
    analogWrite(speaker,0);
    digitalWrite(greenLed, LOW);
    digitalWrite(bcdBlanking,HIGH);
    while (!entered && choice < 4)
    {
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
      choice = 0;
      entered = false;
      incorrect++;
      if(incorrect ==3){
        digitalWrite(redLed,HIGH);
        digitalWrite(bcdBlanking,LOW);
        errorTone();
        delay(2000);
        incorrect=0;
        digitalWrite(bcdBlanking,HIGH);
        digitalWrite(redLed,LOW);
        noTone(speaker);
      }
    }
  }
  while (correct)
  {
    if(executed == false){
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed,LOW);
    digitalWrite(bcdBlanking,LOW);
    unlockTone();
    unlockVault();
    executed = true;
    }
    displayNumber(firstDigit, tnum2, tnum3, tnum4);

    if (digitalRead(resetButton) == LOW)
    {
      digitalWrite(bcdBlanking,HIGH);
      int firstDigit = 0;
      firstDigit = 0;
      num2 = 0;
      num3 = 0;
      num4 = 0;
      choice =0;
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
      correct=false;
      firstDigit = 0;
      tnum1 = 0;
      tnum2 = 0;
      tnum3 = 0;
      tnum4 = 0;
    }

    // checks to see if the door sensor has been trigered is so it locks the vault and resets the led's and display
    if (digitalRead(rotaryButton) == HIGH &&digitalRead(doorSensor)==LOW)
    {
      lockTone();
      correct = false;
      tnum1 = 0;
      tnum2 = 0;
      tnum3 = 0;
      tnum4 = 0;
    }
  }
}
