#include "global.h" //global header file for global variables and so on (arduino.h and other libraries are included in global.h)
#include "header.h" //header flie for funtion prototypes

// variables
#define time1 300
unsigned long Previousmillis = 0;
int password = 0000; // password of the vault
int choice;          // Choice made by the user to use rng or own code
int PWinput;         // password input by the user
int attempts = 1;    // 3 attempts allowwed for the user

void setup()
{
    // attach the servo that's named lock to pin 9(servo)
    lock.attach(servo);

    // generates a seed from the given value that is used in the random() function
    randomSeed(analogRead(A5));

    Serial.begin(9600);

    for (int i = 5; i <= 13; i++)
    {
        pinMode(i, OUTPUT);
    }
    pinMode(rotaryButton, INPUT_PULLUP);

    // interrupts for Rotary enoder
    attachInterrupt(digitalPinToInterrupt(2), encoderChange, CHANGE);
    attachInterrupt(digitalPinToInterrupt(3), encoderChange, CHANGE);
}
int num1, num2, num3, num4;
int dec;
void loop()
{
    if (password == 0000)
    {
        Serial.print("Do you want to make a password(0) or generate one(1)\n");
        Serial.print("Insert a 0 or 1\n");
        choice = Serial.read();
        while ((choice > 1) || (choice < 0))
        {
            Serial.print("Wrong input, try again!\n");
            Serial.print("Enter your choice:\n");
            choice = Serial.read();
        }
        if (choice == 0)
        {
            Serial.print("Insert a password\n");
            password = Serial.read();
        }
        else if (choice == 1)
        {
            Serial.print("Your generated code is: ");
            Serial.print(generateRandomNumber(num1, num2, num3, num4));
        }
        else
        {
            Serial.print("Incorrect choice\n");
            password = Serial.read();
        }
    }
    Serial.print("Insert password:\n");
    input = Serial.read();
}
if (input == password)
{
    Serial.print("Correct password\n");
    Serial.print("LED turns green + buzzer\n");
}
else
{
    while ((input != password) && (input != generateRandomNumber()) && attempts <= 2)
    {
        Serial.print("Incorrect password, Try again:\n");
        input = Serial.read();
        attempts++;
    }

    if (input == generateRandomNumber())
    {
        Serial.print("correct password\n");
        Serial.print("LED turns green + buzzer\n");
    }
    else if (input == password)
    {
        Serial.print("Correct password\n");
        Serial.print("LED turns green + buzzer\n");
    }
}
return 0;
}

// basically does the same as the delay() function but doesn't stop executing everything else.
// unsigned long Currentmillis = millis();
// if ((unsigned long)(Currentmillis - Previousmillis) >= time1)
//{

// Generates a random number for each digit
//  generateRandomNumber(num1, num2, num3, num4);
//  Previousmillis = Currentmillis;
// }

countDigits(dec);
rotaryServo(dec);
rotaryBuzz(dec);
selectDisplay(num1, num2, num3, num4);
displayNumber(num1, num2, num3, num4);
}
