// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // copy word to word-check
    char word_check[LENGTH + 1];
    strcpy(word_check, word);

    for (int i = 0; word_check[i] != '\0';i++)
        {
            word_check[i] = tolower(word_check[i]);
        }

    unsigned hash_number = hash(word);
    for (node *ptr = table[hash_number]; ptr!=NULL; ptr = ptr->next)
    {
        if(strcmp(ptr->word, word_check)==0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return topper(word[0] - 'A');
    unsigned int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("dont read\n");
        return false;
    }

    char word[LENGTH + 1];
    // Read each word in the file

    while (fscanf(input, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(input);
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        int index = hash(word);

        // Chèn vào hash table (danh sách liên kết)
        n->next = table[index];
        table[index] = n;
    }

    // Close the dictionary file
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int count = 0;
    for (int i = 0; i < N; i++)
    {
        for ( node *cursor = table[i]; cursor !=NULL; cursor = cursor->next)
        {
            count++;
        }

    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while ( ptr != NULL)
        {
            node *tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    return true;
}
