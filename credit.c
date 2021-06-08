// TODO:
#include <stdio.h>
#include <cs50.h>

int main(void)
{

    //TODO: Prompt user for input
    long number = get_long("Number: ");


    //Count the amount of digits in number / get length of Number
    long digits = number;
    int count = 0;
    int a;

    do
    {
        a = digits /= 10;
        count++;
    }
    while (digits > 0);

    //Check if Number is valid
    if (count < 13 || count > 16 || count == 14)
    {
        printf("INVALID\n");
        return 0;
    }

    long num = number;
    int mod1;
    int mod2;
    int sum1 = 0;
    int sum2 = 0;
    int dig1;
    int dig2;

    do
    {
        // remove the last digit
        mod1 = num % 10;
        num /= 10;
        sum1 = sum1 + mod1;

        //get second to last digit
        mod2 = num % 10;
        num /= 10;

        //multiply digit
        mod2 *= 2;

        //get individual digits and add together
        dig1 = mod2 % 10;
        dig2 = mod2 / 10;

        sum2 = sum2 + dig1 + dig2;
    }
    while (num > 0);

    int total = sum1 + sum2;

    //get last digit of sum to see if it ends with a 0 - to check if it satisfies the Luhn’s Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //get first two digits
    long n = number;

    do
    {
        n /= 10;
    }
    while (n > 100);

    //check what type of card it is
    if (n == 37 || n == 34)
    {
        printf("AMEX\n");
    }
    else if (n >= 51 && n <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (n / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
