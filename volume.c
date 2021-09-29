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

    // TODO: Copy header from input file to output file


    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);
    //header is an array of 44 uint - So when we fread sizeof(header) at a quantity of 1, we had already read the entire header.

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;
    while (fread(&buffer, sizeof(buffer), 1, input))
    {
        // Update volume
        buffer *= factor;
        fwrite(&buffer, sizeof(buffer), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}

// NOTES:

// header - header in this case is defined as an array of 44 unsigned bytes.
//So when we fread sizeof(header) at a quantity of 1, we had already read the entire header.
//So when the while loop begins, we actually begin reading and writing the byte after the header
//since that is the last most recent point fread left off for the file pointer *input

// Why do we use the "&" when reading/writing to the buffer, but not the header ??
// The array variable itself is already a pointer, just like string (char *).
// This is why when you simply add an array parameter to a function, it will modify
// the source array by default and won't make a local copy.