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

        n->next = NULL;
        if (list == NULL)
        {
            list = n;
        }
        else
        {
            for (node *ptr = list; ptr!= NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }            
        }         
    }

//time pass
for (node *ptr = list; ptr!=NULL; ptr = ptr->next)
{
    printf("%i", ptr->number);
}
return 0;

    
}