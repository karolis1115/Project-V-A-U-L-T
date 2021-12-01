

#include "global.h"

//also stolen code :3
int protectedCount = 0;
int previousCount = 0;
volatile int count = 0;
#define readA bitRead(PIND, DT)  // faster than digitalRead()
#define readB bitRead(PIND, CLK) // faster than digitalRead()

void readEncoder(int &digit)
{
    noInterrupts();
    protectedCount = count;
    interrupts();

    if (protectedCount != previousCount)
    {
        digit = protectedCount;
    }
    previousCount = protectedCount;
}

void isrA()
{
    if (readB != readA)
    {
        count++;
    }
    else
    {
        count--;
    }
}
void isrB()
{
    if (readA == readB)
    {
        count++;
    }
    else
    {
        count--;
    }
}