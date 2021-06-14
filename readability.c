#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// index = 0.0588 * L - 0.296 * S - 15.8 = the formula

int main(void)
{
    string text = get_string("Text: ");

    int charCount = 0; //for characters (letters)
    int spaceCount = 1; // to count spaces (words)
    int sentenceCount = 0; // to count sentences

    //let's iterate through our string using a 'for' loop
    for (int i = 0; text[i] != 0 ; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            charCount++;
        }
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            charCount++;
        }
        //to count words : count spaces and add 1
        if (text[i] == ' ')
        {
            spaceCount++;
        }
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentenceCount++;
        }
    }

    //printf("%i letter(s), %i word(s), %i sentence(s)\n", charCount, spaceCount, sentenceCount);


    float L = (charCount / (float) spaceCount) * 100;
    float S = (sentenceCount / (float) spaceCount) * 100;
    //printf("L %f\n", L);
    //printf("S %f\n", S);

    float index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.f\n", index);
    }

}