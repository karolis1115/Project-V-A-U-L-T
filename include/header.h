#ifndef HEADER_H
#define HEADER_H

//all function protorypes
void displayNumber(int display1, int display2, int display3, int display4);
void rotaryServo(int val);
void encoderChange();
void rotaryBuzz(int val);
void selectDisplay(int &number1, int &number2, int &number3, int &number4);
void countDigits(int &digit);
int generateRandomNumber(int &num1, int &num2, int &num3, int &num4);

#endif
