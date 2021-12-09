#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int count_letters (string st_text);
int count_words (string st_text);
int count_sentences (string st_text);

int main (void)
{
    //ask for text user
    string text = get_string("Text: ");

    //count letters
    int letters = count_letters(text);

    //count words
    int words = count_words(text);

    //count sentences
    int sentences = count_sentences(text);

    //count formula index = 0.0588 * L - 0.296 * S - 15.8
    float L = (letters * 100) / words;
    float S = (sentences*100) / words;

    float INDEX = (0.0588 * L) - (0.296 * S) -15.8;
    int grade = round(INDEX);

    //grade
    if(grade>16)
    {
        printf("%s","Grade 16+\n");
    }
    else
    if(grade<1)
    {
        printf("%s","Before Grade 1\n");
    }
    else
    {
        printf("%s %i", "Grade", grade);
    }
}

// count letters of text
int count_letters (string st_text)
{
    int n=0;
    for (int i=0, k=strlen(st_text); i<k; i++)
    {
        if(isalpha(st_text[i]))
        {
            n++;
        }
    }
    return n;
}

//count words of text
int count_words (string st_text)
{
    int n=1;
    for(int i=0, k=strlen(st_text); i<k; i++)
    {
        if(isspace (st_text[i]))
        {
            n++;
        }
    }
    return n;
}

//count sentences
int count_sentences (string st_text)
{
    int n=0;
     for(int i=0, k=strlen(st_text); i<k; i++)
    {
        if((int)st_text[i] == 46 || (int)st_text[i] ==63 || (int)st_text[i] ==33 )
        {
            n++;
        }
    }
    return n;
}
