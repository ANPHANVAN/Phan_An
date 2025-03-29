#include <stdio.h>
void meow(void);

int main(void)
{
     int i = 0;
    while (i < 3)
    {
        printf("I love you\n");
        i ++;
    }

    printf("The Next Type  for\n");

    for (int i = 0; i < 3; i++)
    {
         printf("I love you 3000\n");
    }
    meow();   
}

void meow(void)
{
    printf("meowwwwww");
}

