#include <cs50.h> //libraries
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name ?\n"); // input from user
    printf("Hello, %s\n", name); // giving answer
}