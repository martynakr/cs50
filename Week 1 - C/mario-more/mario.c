#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    while (height <= 0 || height > 8)
    {
        height = get_int("What height would you like? ");
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height + 3 + i; j++)
        {

            if (j >= height - i - 1)
            {
                if (j < height + 2 && j >= height)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}