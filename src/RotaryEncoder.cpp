#include "global.h"
int count = 0;
Rotary rotary = Rotary(B,A);

void encoderChange()
{
    unsigned char result = rotary.process();
    if (result == DIR_CW)
    {
        count++;
        //a quick way to test the red and green led's
        digitalWrite(greenLed,HIGH);
        digitalWrite(redLed,LOW);
    }
    else if (result == DIR_CCW)
    {
        count--;
        //a quick way to test the red and green led's
        digitalWrite(greenLed,LOW);
        digitalWrite(redLed,HIGH);
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
