#include <cs50.h>
#include <stdio.h>

int main(void)
{

    string card_type = "INVALID\n";

    long number = get_long("What is your credit card number?\n");

    bool thirteenDig = number / 1000000000000 >= 1 && number / 1000000000000 < 10;
    bool fifteenDig = number / 100000000000000 >= 1 && number / 100000000000000 < 10;
    bool sixteenDig = number / 1000000000000000 >= 1 && number / 1000000000000000 < 10;

    int loopAm = 0;

    if (thirteenDig)
    {
        loopAm = 13;
    }

    if (fifteenDig)
    {
        loopAm = 15;
    }

    if (sixteenDig)
    {
        loopAm = 16;
    }

    int sum = 0;
    int sumOfDoubled = 0;
    long div = 10;

    int firstDigit = 0;
    int secondDigit = 0;

    for (int i = 0; i < loopAm; i += 1)
    {

        int digit = number % div;

        if (i == loopAm - 1)
        {
            firstDigit = digit;
        }

        if (i == loopAm - 2)
        {
            secondDigit = digit;
        }

        if (!(i % 2))
        {
            sum += digit;
        }
        else
        {
            int doubled = digit * 2;
            if (doubled >= 10)
            {
                int last = doubled % 10;
                int first = (doubled / 10) % 10;
                sum = sum + first + last;
            }
            else
            {
                sum += doubled;
            }
        }

        number = number / 10;
    }

    int checkSum = sum + sumOfDoubled;

    bool endsIn0 = checkSum % 10 == 0;

    if (endsIn0 && fifteenDig && firstDigit == 3 && (secondDigit == 7 || secondDigit == 4))
    {
        card_type = "AMEX\n";
    }

    if (endsIn0 && (thirteenDig || sixteenDig) && firstDigit == 4)
    {
        card_type = "VISA\n";
    }

    if (endsIn0 && sixteenDig && firstDigit == 5 && secondDigit >= 1 && secondDigit <= 5)
    {
        card_type = "MASTERCARD\n";
    }

    printf("%s", card_type);
}