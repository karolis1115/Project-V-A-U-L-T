#include "global.h"
int count = 0;
Rotary rotary = Rotary(B,A);

void encoderChange()
{
    unsigned char result = rotary.process();
    if (result == DIR_CW)
    {
        count++;
        //Serial.println(count);
    }
    else if (result == DIR_CCW)
    {
        count--;
        //Serial.println(count);
    }
}
void countDigits(int &digit){
    if(count >9){
        count=0;
    }
    if (count <0){
        count =9;
    }
    digit=count;
}
