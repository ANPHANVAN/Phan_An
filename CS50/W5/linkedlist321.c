#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("dont have enough memory\n");
            free(n);
            return 1;
        }

        int scanfnumber;
        scanf("%i", &scanfnumber);
        n->number = scanfnumber;

        n->next = list;
        
        list = n;  
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i", ptr->number);
        ptr = ptr->next;
    }
    
}