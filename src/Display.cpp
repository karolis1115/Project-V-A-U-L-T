#include "global.h"

// this is the map for the numbers
byte numberMap[10]{
    0b0000, // 0
    0b0001, // 1
    0b0010, // 2
    0b0011, // 3
    0b0100, // 4
    0b0101, // 5
    0b0110, // 6
    0b0111, // 7
    0b1000, // 8
    0b1001, // 9
};

// this is the map for the display selection (for common anode and is used for the final pcb)
/*byte displaySelectMap[4]{
    0b0001, // display 1
    0b0010, // display 2
    0b0100, // display 3
    0b1000  // display 4
};*/

//this is for a common cathode display which is used in the 1st protorype
byte displaySelectMap[4]{
    0b1110, // display 1
    0b1101, // display 2
    0b1011, // display 3
    0b0111  // display 4
};

// this is the variable that stores the merged maps
byte fullMap;

void displayNumber(int num1, int num2, int num3, int num4)
{

  // First display
  fullMap = displaySelectMap[0] << 4 | numberMap[num1];
  shiftOut(data, registerClock, MSBFIRST, fullMap);

  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);

  // Second digit
  fullMap = displaySelectMap[1] << 4 | numberMap[num2];
  shiftOut(data, registerClock, MSBFIRST, fullMap);

  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);

  // Third digit
  fullMap = displaySelectMap[2] << 4 | numberMap[num3];
  shiftOut(data, registerClock, MSBFIRST, fullMap);

  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);

  // Fourth digit
  fullMap = displaySelectMap[3] << 4 | numberMap[num4];
  shiftOut(data, registerClock, MSBFIRST, fullMap);

  digitalWrite(latchClock, HIGH);
  digitalWrite(latchClock, LOW);
  delay(5);
}
int display =1;
int released = 1;
// A function that changes which display to change the number on when pressing the encoder shaft
void selectDisplay(int &number1, int &number2, int &number3, int &number4, int& choice)
{
  
  // checks if the button has been pressed
  if (digitalRead(rotaryButton) == 0)
  {
    // checks to see if the button has been released previously
    if (released == 1)
    {
      {
        choice++;
        // bounds for the displays
        if (display < 4)
        {
          display++;
        }
        else
          display = 1;
      }
      released = 0;
      // at each button press set the count back to 0 so you wouldn't start off at the last inputed digit
      count =0;
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