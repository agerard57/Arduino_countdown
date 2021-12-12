#include <math.h>

#define OFF HIGH
#define ON LOW

int digits[] = {13, 12, 11, 10};
int dp = 9;
int f = 7;
int g = 8;
int e = 6;
int d = 5;
int c = 4;
int b = 3;
int a = 2; // 7 Segment pin multiplexed

int countdown = 60;
int count = 4;
int dt = 500; // Stands for "delay time"

struct struct_digits
{
    int digit[4];
};

void setup()
{
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(a, OUTPUT);
    pinMode(dp, OUTPUT);

    pinMode(A0, OUTPUT); // A0 is the 8th pin
    pinMode(A1, OUTPUT); // This is COMM

    for (int i = 0; i < 4; i++)
    {
        pinMode(digits[i], OUTPUT);
    }
}

void loop()
{
    // digitalWrite(A1,OFF);
    // analogWrite(A0,255);
    // These two lines allow the colon to light up

    while (count > 0)
    {
        digit(count);
        for (int i = 9; i >= 0; i--)
        {
            number(i);
            delay(dt);
        }
        count--;
    }
    // Old method I did, this'll change

    // digitalWrite(dp,OFF); //decimal point high
    // delay(dt);
    // digitalWrite(dp,ON); // decimal point low
    // delay(dt);
    // Thanks to these lines, we can turn off and on the decimal point if we wanted
}

void digit(int digit)
{
    for (int i = 0; i <= 4; i++)
    {
        if (i == digit)
        {
            digitalWrite(digits[i], ON);
        }
        else
        {
            digitalWrite(digits[i], OFF);
        }
    }
}

void number(int number)
{
    switch (number)
    {
    case 0:
        digitalWrite(a, OFF);
        digitalWrite(b, OFF);
        digitalWrite(c, OFF);
        digitalWrite(d, OFF);
        digitalWrite(e, OFF);
        digitalWrite(f, OFF);
        digitalWrite(g, ON);
        break;

    case 1:
        digitalWrite(a, ON);
        digitalWrite(b, OFF);
        digitalWrite(c, OFF);
        digitalWrite(d, ON);
        digitalWrite(e, ON);
        digitalWrite(f, ON);
        digitalWrite(g, ON);
        break;

    case 2:
        digitalWrite(a, OFF);
        digitalWrite(b, OFF);
        digitalWrite(c, ON);
        digitalWrite(d, OFF);
        digitalWrite(e, OFF);
        digitalWrite(f, ON);
        digitalWrite(g, OFF);
        break;

    case 3:
        digitalWrite(a, OFF);
        digitalWrite(b, OFF);
        digitalWrite(c, OFF);
        digitalWrite(d, OFF);
        digitalWrite(e, ON);
        digitalWrite(f, ON);
        digitalWrite(g, OFF);
        break;

    case 4:
        digitalWrite(a, ON);
        digitalWrite(b, OFF);
        digitalWrite(c, OFF);
        digitalWrite(d, ON);
        digitalWrite(e, ON);
        digitalWrite(f, OFF);
        digitalWrite(g, OFF);
        break;

    case 5:
        digitalWrite(a, OFF);
        digitalWrite(b, ON);
        digitalWrite(c, OFF);
        digitalWrite(d, OFF);
        digitalWrite(e, ON);
        digitalWrite(f, OFF);
        digitalWrite(g, OFF);
        break;

    case 6:
        digitalWrite(a, ON);
        digitalWrite(b, ON);
        digitalWrite(c, OFF);
        digitalWrite(d, OFF);
        digitalWrite(e, OFF);
        digitalWrite(f, OFF);
        digitalWrite(g, OFF);
        break;

    case 7:
        digitalWrite(a, OFF);
        digitalWrite(b, OFF);
        digitalWrite(c, OFF);
        digitalWrite(d, ON);
        digitalWrite(e, ON);
        digitalWrite(f, ON);
        digitalWrite(g, ON);
        break;

    case 8:
        digitalWrite(a, OFF);
        digitalWrite(b, OFF);
        digitalWrite(c, OFF);
        digitalWrite(d, OFF);
        digitalWrite(e, OFF);
        digitalWrite(f, OFF);
        digitalWrite(g, OFF);
        break;

    case 9:
        digitalWrite(a, OFF);
        digitalWrite(b, OFF);
        digitalWrite(c, OFF);
        digitalWrite(d, ON);
        digitalWrite(e, ON);
        digitalWrite(f, OFF);
        digitalWrite(g, OFF);
        break;
    default:
        digitalWrite(a, ON);
        digitalWrite(b, ON);
        digitalWrite(c, ON);
        digitalWrite(d, ON);
        digitalWrite(e, ON);
        digitalWrite(f, ON);
        digitalWrite(g, ON);
        break;
    }
}