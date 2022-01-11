#ifndef HEADER_H
#define HEADER_H

// all function protorypes
void displayNumber(int display1, int display2, int display3, int display4);
void rotaryServo(int val);
void encoderChange();
void rotaryBuzz(int val);
void selectDisplay(int &number1, int &number2, int &number3, int &number4,int &choice);
int countDigits();
int generateRandomNumber(int &num1, int &num2, int &num3, int &num4);
void ReadAccelerometer(float &accX, float &accY, float &accZ);
void getTransmission(char Trans);
void unlockTone();
void unlockVault();
void lockVault();
void errorTone();
void lockTone();
#endif
