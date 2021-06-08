#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // TODO: Prompt for START size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for END size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    int total = start;

    // TODO: Calculate number of years until we reach threshold - use intergers
    int years = 0;

    while (total < end)
    {
        total = (total + (total / 3) - (total / 4));
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}