#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_args (int args);
bool check_argv (char argv[]);

int main (int args, string argv[])
{   
    bool answer_args = check_args(args);
    if (answer_args==true)
    {
        bool answer_argv = check_argv(argv[1]);
        
        if(answer_argv == true)
        {
            //переписала в ключ массив как масив символов
            int lenght = strlen(argv[1]);
            char key[lenght];
            for (int i = 0; i < lenght; i++)
            {
                key[i]=argv[1][i];
            }
            
            string plaintext = get_string("plaintext: ");
            
            //сделала копию плеинтекст  в аппер кейсе
            int lenght2 = strlen(plaintext);
            char st_plaintext[lenght];
            for (int k = 0; k < lenght; k++)
            {
                st_plaintext[k]=toupper(plaintext[k]);
            }
            
            printf("%s", "ciphertext: ");
            
            for (int l = 0; l < lenght2; l++)
            {
                if(((int)plaintext[l]>=65 && (int)plaintext[l]<=90) || ((int)plaintext[l]>=97 && (int)plaintext[l]<=122))
                {       
                    char ciphertext[l];
                    int k = (int)(st_plaintext[l]) - 65;
                    ciphertext[l]=key[k];
                    if(islower(plaintext[l]))
                    {
                        ciphertext[l]=tolower(ciphertext[l]);
                    }
                    printf("%c", ciphertext[l]);
                }
                else
                {
                    printf("%c", plaintext[l]);
                }
            }
        }
        else
        {
            printf("%s", "Usage: ./caesar key (at least 26 characters)"); 
        }
    }
    else
    {
        printf("%s", "Usage: ./caesar key (at least 26 characters)"); 
    }
}


//два ли аргумента?
bool check_args (int args)
{
    bool check;
    if (args==2)
    {
        check=true;
    }
    else
    {
        check=false;
    }
    return check;
}

//26 ли символов? они буквы?
bool check_argv (char argv[])
{
    bool check;
    int n=strlen(argv);
    if(n==26)
    {
        for (int i = 0; i < n; i++)
        {
            if(isalpha(argv[i]))
            {
                check=true;
            }
            else
            {
                check=false;
                break;
            }
        }
    }
    else
    {
        check=false;
    }
    return check;
}



 
