#include "global.h"

// common cathode 7-segment display map
// int digitMap[11]{ 126, 12, 182, 158, 204, 218, 250, 14, 254, 222, 0 };
int digitMap[12]{
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

  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);

  // Second display
  shiftOut(data, registerClock, MSBFIRST, digitMap[display2]);
  digitalWrite(display1En, HIGH);
  digitalWrite(display2En, LOW);
  digitalWrite(display3En, HIGH);
  digitalWrite(display4En, HIGH);

  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);

  // Third display
  shiftOut(data, registerClock, MSBFIRST, digitMap[display3]);
  digitalWrite(display1En, HIGH);
  digitalWrite(display2En, HIGH);
  digitalWrite(display3En, LOW);
  digitalWrite(display4En, HIGH);

  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);

  // Fourth display
  shiftOut(data, registerClock, MSBFIRST, digitMap[display4]);
  digitalWrite(display1En, HIGH);
  digitalWrite(display2En, HIGH);
  digitalWrite(display3En, HIGH);
  digitalWrite(display4En, LOW);

  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);
}