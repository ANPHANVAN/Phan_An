#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;
    while (1)
    {
        x = get_int("Height: ");

        if ((x > 0) && (x < 9))
        {
            break;
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (j < x - i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");

        for (int j = 0; j < x; j++)
        {
            if (j < i + 1)
            {
                printf("#");
            }
            else
            {
                break;
            }
        }
        printf("\n");
    }
}
