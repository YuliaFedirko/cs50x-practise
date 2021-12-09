#include <cs50.h>
#include <stdio.h>

void space(int n);
void mark(int k);

int main(void)
{
    int h;
    do
    {    
    h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    
    int k=1;
    int u=1;
    for(int g=0;g<h;g++)
    {
        space(h-k);
        mark(u);
        printf("  ");
        mark(u);
        k++;
        u++;
        printf("\n");
    }
    
    
   
}


void space(int n)
{
    for(int i=0;i<n; i++)
    printf(" ");
}

void mark(int k)
{
    for(int j=0;j<k; j++)
    printf("#");
}