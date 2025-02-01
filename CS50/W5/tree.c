#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct table
{
    char *name;
    char *number;
    struct table *next;
} table;

int main(void)
{
    table *n[26];
    for(int i = 0; i < 5; i++)
    {
    table *firstlink = malloc(sizeof(table));
    printf("nhập tên: ");
    scanf("%c", &firstlink->next);
    printf("nhập sdt: ");
    scanf("%c", &firstlink->next); 
    firstlink->next = NULL;
    
    // chưa hoàn thành
    }
}