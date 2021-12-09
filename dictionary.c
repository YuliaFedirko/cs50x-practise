// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include  <stdlib.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50000;

int numberofwords;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashcode = hash(word);
    bool found = false;
    
    node *cursor = table[hashcode];
    
    while(cursor != NULL)
    {
        
        if(strcasecmp(word, cursor -> word) == 0)
        {
            found = true;
        }
        
        cursor = cursor -> next;
        
    }
    return found;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    // initialize index to 0
    int index = 0;

    // sum ascii values
    for (int i = 0; word[i] != '\0'; i++)
    {
        index += toupper(word[i]);
    }

    // mod by size to stay w/in bound of table
    return index % N;

    
    //
    
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *f = fopen(dictionary, "r");
    if(f == NULL)
    {
        fclose(f);
        return false;
    }
    
    char word_tmp[LENGTH+1];
    unsigned int new_hash;
    
    
    while(fscanf(f, "%s", word_tmp) != EOF)
    {
        node *n = malloc(sizeof(node));
        
        if(n == NULL)
        {
            fclose(f);
            return false;
            
        }
        
        strcpy(n -> word, word_tmp);
        n -> next = NULL;
        
        new_hash = hash(n -> word);
       
        if(table[new_hash] == NULL)  
        {
            table[new_hash] = n;
            printf("%s", table[new_hash] -> word);
        }
        else
        {
            n -> next = table[new_hash];
            table[new_hash] = n;
        }
        
        numberofwords++;
        
    }
    fclose(f);
    
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    
    return numberofwords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int j = 0; j < N; j++)
    {
        node *tmp = table[j];
        node *cursor = table[j];
        
        while(cursor != NULL)
        {
            
            cursor = cursor -> next;
            free(tmp);
            tmp = cursor;
          
        }
    }
    
    return true;
}
