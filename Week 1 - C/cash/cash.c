#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int change = 0;

    while (change <= 0)
    {
        change = get_int("How much change is owed? ");
    }

    int sum = 0;

    int remaining = change;

    int coins[] = {25, 10, 5, 1};

    for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); i++)
    {
        int coinsAm = (remaining / coins[i]);
        sum += coinsAm;
        remaining = remaining % coins[i];
    }

    printf("%i ", sum);
}
