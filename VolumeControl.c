// Modifies the volume of an audio file
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    uint8_t header[HEADER_SIZE]; //Buffer for storing header
    
    fread(header, sizeof(uint8_t), HEADER_SIZE, input); //Reads 44 bytes of information (header) from input file and stores it in the buffer header
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output); //Writes 44 bytes of informaion from buffer (header) into output file, effectively copying the header into the output file
    
    int16_t sample; //Variable that will store each sample and modify it
    
    while (fread(&sample, sizeof(int16_t), 1, input)) //Loops through each sample (16-bit, 2 bytes) and reads it into sample
    {
        sample *= factor; //Sample is then scaled by the factor
        fwrite(&sample, sizeof(int16_t), 1, output); //Writes the updated sample into the output file
    }
    
    // Close files
    fclose(input);
    fclose(output);
}
