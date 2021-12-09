#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int args, string argv[])
{   
    if(args == 2)
    {
   
        //переписала в ключ массив как масив символов
        int lenght = strlen(argv[1]);
        char key[lenght];
        for (int i = 0; i < lenght; i++)
        {
            key[i]=argv[1][i];
        }
         
        bool check;
        for (int i = 0; i < lenght; i++)
        {
            if(isdigit(key[i]))
            {
                check=true;
            }
            else
            {
                check=false;
                break;
            }
            if (check == true)
            {
               // printf("%s", "Success");
                //return 1;

                //получаем текст для шифра
                string plaintext = get_string("plaintext: ");
                printf("%s", "ciphertext: ");
                
                int n = strlen(plaintext);
                char ciphertext[n];
                
                //ковнертация арея ключа в цифру
                
                int key_st = atoi(key);
                //printf(" %i ", key_st);
                
                //код для шифра
                for (int k = 0; k < n; k++)
                {
                    if(((int)plaintext[k]>=65 && (int)plaintext[k]<=90) || ((int)plaintext[k]>=97 && (int)plaintext[k]<=122))
                    {       
                        ciphertext[k]=(((int)plaintext[k]-97+key_st) % 26) + 97;
                        //printf(" %c ", plaintext[k]);
                        if(isupper(plaintext[k]))
                        {
                            ciphertext[k]=toupper(ciphertext[k]);
                        }
                    }
                    else
                    {
                        ciphertext[k]=plaintext[k];
                    }
                    
                    printf("%c", ciphertext[k]);
                }
            }
        }
    }
    else
    {
        printf("%s", "Usage: ./caesar key");
        //return 0;
    }
}



