/*Rotary encoder handler for arduino. v1.1

Copyright 2011 Ben Buxton. Licenced under the GNU GPL Version 3. Contact: bb@cactii.net

A typical mechanical rotary encoder emits a two bit gray code on 3 output pins. Every step in the output (often accompanied by a physical 'click') generates a specific sequence of output codes on the pins.

There are 3 pins used for the rotary encoding - one common and two 'bit' pins.
*/
#include "global.h"
int count = 0;
Rotary rotary = Rotary(B,A);

void encoderChange()
{
    unsigned char result = rotary.process();
    if (result == DIR_CW)
    {
        count++;
    }
    else if (result == DIR_CCW)
    {
        count--;
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
