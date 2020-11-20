#include <cs50.h> // libraries
#include <stdio.h>

int main(void)
{
    int n; //define a variable
    do
    {
        n = get_int("Size: "); // input from user
    }
    while (n < 1 || n > 8); // integer values must be in between 1 and 8
    for (int i = 0; i < n; i ++) // general loop 
    {
        for (int k = i; k + 1 < n; k++) // loop for the number of spaces that should be 
        {
            printf(" ");
        }
        for (int j = n - i; j <= n; j++) // as many # to print
        {
            printf("#");
        }
        printf("\n"); //for new line
    }
}