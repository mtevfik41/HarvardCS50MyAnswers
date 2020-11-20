#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    long long num;
    int count = 0;

    // input number from user
    num = get_long("Number: ");

    /* FINDING LENGTH OF CC NUM */
    // calculate total digits
    count = (num == 0) ? 1  : (log10(num) + 1);
    // printf("Total digits: %d\n", count);

    /* FINDING FIRST NUMBERS OF CC NUM*/
    int firstNums;
    if (count == 15)
    {
        firstNums = num / 10000000000000;
    }
    else if (count == 16)
    {
        firstNums = num / 1000000000000000;
        if (firstNums == 5)
        {
            firstNums = num / 100000000000000;
        }
    }
    else if (count == 13)
    {
        firstNums = num / 1000000000000;
    }
    // else {
    //     printf("INVALID\n");
    // }

    //LUHNS ALGORITHM
    int length;
    if (count == 16)
    {
        length = count / 2;
    }
    else
    {
        double halfLength = count / 2;
        length = ceil(halfLength) + 1;
        // printf("length: %d\n", length);
    }

    //get even digits starting with last in card number
    int evenDigits[length];
    long long evenNum = num;
    for (int i = 0; i < length; i++)
    {
        evenDigits[i] = evenNum % 10;
        evenNum /= 100;
        // printf("even: %d, iter: %d\n", i, evenDigits[i]);
    }

    //get odd digits starting with second-to-last in card number
    int oddDigits[length];
    num /= 10;
    for (int i = 0; i < length; ++i)
    {
        oddDigits[i] = (num % 10) * 2; // multiply number by two and push to array
        num /= 100;
        // printf("odd: %d, iter: %d\n", i, oddDigits[i]);
    }

    int oddSum = 0;
    for (int i = 0; i < length; i++)
    {
        if (oddDigits[i] > 9)
        {
            // printf("%d is a double digit number\n", oddDigits[i]);
            oddSum = oddSum + oddDigits[i] % 10;
            int temp = oddDigits[i] / 10;
            oddSum = oddSum + temp % 10;
        }
        else
        {
            oddSum = oddSum + oddDigits[i];
        }
    }
    // printf("%d is the oddSum\n", oddSum);

    int evenSum = 0;
    for (int i = 0; i < length; i++)
    {
        evenSum = evenDigits[i] + evenSum;
        // printf("i: %d, num: %d\n", i, evenDigits[i]);
    }
    // printf("%d is the evenSum\n", evenSum);

    int totalSum = evenSum + oddSum;
    // printf("%d is the totalSum\n", totalSum);

    int test = totalSum % 10;
    // printf("is zero: %d\n", test);

    if (test == 0)
    {
        //TEST CARD NUMBER
        //AMEX len:15; start:34||37
        if (count == 15 && (firstNums == 34 || firstNums == 37))
        {
            printf("AMEX\n");
        }
        //MASTERCARD len:16; start:51||52||53||54||55
        else if ((firstNums == 51 || firstNums == 52 || firstNums == 53 || firstNums == 54 || firstNums == 55) && count == 16)
        {
            printf("MASTERCARD\n");
        }
        //VISA len:13||16; start:4
        else if ((firstNums == 4) && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}