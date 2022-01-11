#include "global.h"
// A quick buzzer test, the frequency will change based on the rotary encoder count
void rotaryBuzz(int val)
{
    // tone(speaker, map(val,0,9,1000,10000));
}

int previous;
void unlockTone()
{
     tone(speaker,500,250);
   delay(250);
   tone(speaker,1000,250);
}
void lockTone()
{
    tone(speaker,1000,250);
   delay(250);
   tone(speaker,500,250);
}

void errorTone()
{
   tone(speaker,1000);
   delay(250);
   tone(speaker,500);
}

// basically does the same as the delay() function but doesn't stop executing everything else.
// unsigned long Currentmillis = millis();
// if ((unsigned long)(Currentmillis - Previousmillis) >= time1)
//{

//}