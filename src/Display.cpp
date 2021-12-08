#include "global.h"

// common cathode 7-segment display map
// int digitMap[11]{ 126, 12, 182, 158, 204, 218, 250, 14, 254, 222, 0 };
byte digitMap[12]{
    0b01111110, // digit 0
    0b00001100, // digit 1
    0b10110110, // digit 2
    0b10011110, // digit 3
    0b11001100, // digit 4
    0b11011010, // digit 2
    0b11111010, // digit 6
    0b00001110, // digit 7
    0b11111110, // digit 8
    0b11011110, // digit 9
    0b00000000, // all digits off
    0b00000001  // dot or led on
};

void displayNumber(int display1, int display2, int display3, int display4)
{
  // First display
  shiftOut(data, registerClock, MSBFIRST, digitMap[display1]);
  digitalWrite(display1En, LOW);
  digitalWrite(display2En, HIGH);
  digitalWrite(display3En, HIGH);
  digitalWrite(display4En, HIGH);

  // pulse the latchClokc pin
  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);

  // Second display
  shiftOut(data, registerClock, MSBFIRST, digitMap[display2]);
  digitalWrite(display1En, HIGH);
  digitalWrite(display2En, LOW);
  digitalWrite(display3En, HIGH);
  digitalWrite(display4En, HIGH);

  // pulse the latchClokc pin
  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);

  // Third display
  shiftOut(data, registerClock, MSBFIRST, digitMap[display3]);
  digitalWrite(display1En, HIGH);
  digitalWrite(display2En, HIGH);
  digitalWrite(display3En, LOW);
  digitalWrite(display4En, HIGH);

  // pulse the latchClokc pin
  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);

  // Fourth display
  shiftOut(data, registerClock, MSBFIRST, digitMap[display4]);
  digitalWrite(display1En, HIGH);
  digitalWrite(display2En, HIGH);
  digitalWrite(display3En, HIGH);
  digitalWrite(display4En, LOW);

  // pulse the latchClokc pin
  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);
}

int display = 1;
int released = 1;
// A function that changes which display to change the number on when pressing the encoder shaft
void selectDisplay(int &number1, int &number2, int &number3, int &number4)
{
  // checks if the button has been pressed
  if (digitalRead(rotaryButton) == 0)
  {
    // checks to see if the button has been released previously
    if (released == 1)
    {
      {
        //bounds for the displays
        if (display < 4)
        {
          display++;
        }
        else
          display = 1;
      }
      released = 0;
      //at each button press set the count back to 0 so you wouldn't start off at the last inputed digit
      count=0;
    }
  }

  switch (display)
  {
  case 1:
    number1 = count;
    break;

  case 2:
    number2 = count;
    break;

  case 3:
    number3 = count;
    break;

  case 4:
    number4 = count;
    break;
  }

  // if button is released set variable released to 1
  if (digitalRead(rotaryButton) == 1)
  {
    released = 1;
  }
}