#include "global.h"

int generateRandomNumber(int min, int max, int &num1, int &num2, int &num3, int &num4)
{
  randomSeed(analogRead(A5)); // generates a seed from the given value that is used in the random() function

  // generates a random number between min and max (for 1 digit it's from 0 to 9).
  num1 = random(min, max);
  num2 = random(min, max);
  num3 = random(min, max);
  num4 = random(min, max);
  return 0;
}