#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int x = get_int("Number: ");
    int k=0;
    float p=x;
    do
    {
       p=p/1e1;
      // printf("%i", k);
    //    printf("pip %f", p);
        k++;
    }
    while (p>1);
   // printf("%i ", k);
  float sum=0;
  int s=0;
  int b;
  do
   {
  b=x%10;
  x=x/10;
  x=(int)x;
//    printf("%i", b);
 //    printf("piss %i ", x);
    sum=sum+b;
    s++;
    
 //  printf("%i", s);
  //  printf("%i pip \n", k);
   
    }
   while (s<k);
   printf("%i", (int)sum);
    
   
}

