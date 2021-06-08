#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, j, k, space, hash;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (row = 0; row < height; row++) //rows
    {
        for (j = (height - 1); j > row; j--) //spaces
        {
            printf(" ");
        }
        for (k = 0; k <= row; k++) //# left
        {
            printf("#");
        }

        for (space = 0; space < 2 ; space++) //space in the middle
        {
            printf(" ");
        }
        for (hash = 0; hash <= row; hash++) //hashes right
        {
            printf("#");
        }
        printf("\n");
    }
}