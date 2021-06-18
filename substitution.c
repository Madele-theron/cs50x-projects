#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char A = 'A';

int main(int argc, string argv[])
{
    // INVALID KEY : if user gives less or more than 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // count length of string in argv[1]
    int n = strlen(argv[1]);

    // INVALID KEY : if user input is more than 26 characters
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int count[26] = {0}; //initialize all 26 arrays to zero (array of all zero)
    char *key = argv[1];

    //error: incompatible pointer to integer conversion initializing 'char' with an expression of type 'string' (aka 'char *'); dereference with * [-Werror,-Wint-conversion]
    //char key = argv[1];
    //     ^     ~~~~~~~
    //           *

    for (int i = 0; i < n; i++)
    {
        // INVALID KEY : if user input contains non alphabetical characters
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        count[toupper(key[i]) - A]++;  //
    }

    // INVALID KEY : if user repeats a character
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }

    string pt = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, m = strlen(pt); i < m; i++)
    {
        if (isupper(pt[i]))
        {
            int uppercase = pt[i] - 'A';
            char upper = toupper(key[uppercase]);
            printf("%c", upper);
        }
        else if (islower(pt[i]))
        {
            int lowercase = pt[i] - 'a';
            char lower = tolower(key[lowercase]);
            printf("%c", lower);
        }
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
    return 0;
}