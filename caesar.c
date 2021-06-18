#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // convert string to int
        int key = atoi(argv[1]);

        // prompt user for plaintext
        string pt = get_string("plaintext: ");

        //
        printf("ciphertext: ");

        for (int i = 0, n = strlen(pt); i < n; i++)
        {
            if (isalpha(pt[i]))
            {
                if (isupper(pt[i]))
                {
                    //convert to ASCII to alphabetical index
                    int uppercase = pt[i] - 'A';

                    // shift alphabetical index using formula
                    int shift = (uppercase + key) % 26;

                    // convert result back to ASCII
                    int ascii = shift + 'A';
                    printf("%c", ascii);
                }
                else if (islower(pt[i]))
                {
                    int lowercase = pt[i] - 'a';
                    int shift = (lowercase + key) % 26;
                    int ascii = shift + 'a';
                    printf("%c", ascii);
                }
            }
            else
            {
                printf("%c", pt[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}