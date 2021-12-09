#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("%s\n", "Usage: ./recover infile");
        return 1;
    }
    
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "Could not open\n");
        return 1;
    }
    
    BYTE *buffer = malloc(512);
    //BYTE buffer[512];
    
    int i = -1;
    bool found = false;
    char filename[8];
    //FILE* img = fopen(filename, "w");
    FILE* img = NULL;
    
    //while(feof(f) == 0)
    while(fread(buffer, 512, 1, f) == 1)
    {
        //fread(buffer, 512, 1, f);
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if(found == false)
            {
                i++;
                found = true;
                
                sprintf(filename, "%03i.jpg", i);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                //printf("hello");
            }
            else
            {
                fclose(img);
                
                i++;
                
                sprintf(filename, "%03i.jpg", i);
                img = fopen(filename, "w");
                
                fwrite(buffer, 512, 1, img);
                //printf("%i\n", i);
            }
        }
        else
        {
            if(found == true)
            {
                fclose(img);
                //printf("%i\n", i);
                img = fopen(filename, "a");
                fwrite(buffer, 512, 1, img);
            }
        }
        
    }
    fclose(img);
    fclose(f);
    free(buffer);
    
    
    
}