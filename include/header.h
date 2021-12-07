#ifndef HEADER_H
#define HEADER_H

//all funtion protorypes
void ReadAcc7_seg(int &x, int &y, int &z);
void displayNumber(int display1, int display2, int display3, int display4);
void readEncoder(int &digit);
int generateRandomNumber(int min, int max, int &num1, int &num2, int &num3, int &num4);
void isrA();
void isrB();

#endif
