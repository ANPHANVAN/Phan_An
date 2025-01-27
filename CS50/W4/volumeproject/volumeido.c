#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

    const int HEADER = 44;
int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("try again with sample: ./volume2 input.wav output.wav 2.0\n");
        return 1;
    }

    FILE *input = fopen(argv[1],"r");  
    if (input == NULL)
    {
        printf("file input dont exit\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("output dont have\n");
        return 1;
    }

    float factor = atof(argv[3]);

    uint8_t HEAD[HEADER];
    fread(HEAD, HEADER, 1, input);
    fwrite(HEAD, HEADER, 1, output);


    uint16_t buffer;
    while (fread(&buffer, sizeof(uint16_t), 1, input))
    {
        buffer *= factor;
        
        fwrite(&buffer, sizeof(uint16_t), 1, output);
    }
    
    fclose(input);
    fclose(output);


}