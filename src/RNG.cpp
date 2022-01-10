#include "global.h"

int generateRandomNumber(int &num1, int &num2, int &num3, int &num4)
{
  // generates a seed from the given value that is used in the random() function
  randomSeed(millis());
  int min = 0;
  int max = 10;

  // generates a random number for each digit between min and max (for 1 digit it's from 0 to 9).
  num1 = random(min, max);
  num2 = random(min, max);
  num3 = random(min, max);
  num4 = random(min, max);
  return 0;
}