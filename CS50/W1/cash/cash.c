#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int cents, coins = 0;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    printf("%d\n", cents);
    // Đếm số xu cần trả lại
    coins += cents / 25; // Số quarters (25 cents)
    cents %= 25;

    coins += cents / 10; // Số dimes (10 cents)
    cents %= 10;

    coins += cents / 5; // Số nickels (5 cents)
    cents %= 5;

    coins += cents / 1; // Số pennies (1 cent)

    printf("%d\n", coins);
}
