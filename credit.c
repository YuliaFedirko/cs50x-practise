#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n;
    do
    {
        n = get_long("Number:" );
    }
    while (n<4000000000000 || n>5500000000000000);
   
    long u=n;
    int a=0;
    do
    {
            u=u/1e1;
            a++;
    }
    while((u)>1);
   
   int p;
   int k=2;
   int l=1;
   int x;
   int x2;
   int y;
   int y2;
   int sum = 0;
   int sum2 =0;
   int k1;

  
    k1=(k/2)%10;
    if (k1==0)
    {
        do
        {
            x=n%10^l;
            sum=+x;
            l=l+2;
        }
        while(l<=a);
        do
        {
            y=n%10^k;
            y2=y*2;
            if(y2>10)
            {
                y2=y2%10+(int)y2/10;
                sum2=+y2;
                l=k+2;
            }
            else
            {
                sum2=+y2;
                l=k+2;
            }
        }
        while(k<=a);
    }
    else
     {
        do
        {
            x=n%10^k;
            sum=+x;
            l=k+2;
        }
        while(k<=a);
        do
        {
            y=n%10^l;
            y2=y*2;
            if(y2>10)
            {
                y2=y2%10+(int)y2/10;
                sum2=+y2;
                l=l+2;
            }
            else
            {
                sum2=+y2;
                l=l+2;
            }
        }
        while(l<=a);
    }
   printf("%i,%i", sum,sum2);
}

