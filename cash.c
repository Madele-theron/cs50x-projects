#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // declare variable float
    float Change;
    // declare variable float

    // prompt user for input. Re-prompt user until input is a non-negative value.
    do
    {
        Change = get_float("Change owed: ");
    }
    while (Change < 0); //prompts user again until value is positive.

    int coins = round(Change * 100);
    //printf("%.2f\n", x);

    // count the amount of coins used and store as an interger.
    int coinNum = 0;

    while (coins >= 25)
    {
        coinNum ++;
        coins = coins - 25;
    }

    while (coins >= 10)
    {
        coinNum++;
        coins = coins - 10;
    }

    while (coins >= 5)
    {
        coinNum++;
        coins = coins - 5;
    }

    while (coins >= 1)
    {
        coinNum++;
        coins = coins - 1;
    }



    printf("%i\n", coinNum);


}