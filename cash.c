#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollar;
    do
    {
    dollar = get_float("Change owed: ");
    }
    while( dollar <= 0);
    int cent = round(dollar*100);
    //    printf("%i ", cent);

    int k=0;
    do
    {
        if(cent-25>=0)
        {
            cent=cent-25;
            k++;
                if(cent>=10)
                {
                    cent=cent-10;
                    k++;
                }
                    if(cent>=5)
                    {
                        cent=cent-5;
                        k++;
                    }
                        if(cent>=1)
                        {
                            cent=cent-1;
                            k++;
                        }
        } 
        else
        if(cent-10>=0)
        {
            cent=cent-10;
            k++;
            if(cent>=5)
            {
                cent=cent-5;
                k++;
            }
                if(cent>=1)
                {
                    cent=cent-1;
                    k++;
                }
        } 
        else
        if(cent-5>=0)
        {
            cent=cent-5;
            k++;
            if(cent>=1)
            {
                cent=cent-1;
                k++;
            }
        } 
         else
        if(cent-1>=0)
        {
            cent=cent-1;
            k++;
        } 
    }
    while(cent>0);
   
    printf("%i", k);
    
}