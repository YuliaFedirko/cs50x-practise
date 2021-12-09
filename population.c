#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int s;
    do 
    {
        s = get_int("Start size: ");
    }
    while (s < 9);
   
    int e;
    do 
    {
        e = get_int("End size: ");
    }
    while (e < s);
    int p=s;
    int n=0;
    
    do
    {
       p = p+(int)p/3-(int)p/4;
       n++;
    }
    while (p<e);
    
    printf("Years:%i\n", n);
}

   
