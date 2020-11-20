#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Enter your text: "); // taking input from user
    int lettercount = 0; // counter for letters
    int wordcount = 1; // counter for words
    int sentencecount = 0; // counter for sentences
    int textLength = strlen(text); // calculating length of text

    for (int i = 0; i < textLength; i++) // for loop for input array
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) //letter conditions

        {
            lettercount++;
        }
        if (text[i] == ' ') // word condition
        {
            wordcount++;
        }
        if (text[i] == '!' || text[i] == '.' || text[i] == '?') // sentence conditions
        {
            sentencecount++;
        }
    }
    //Coleman-Liau Index

    float L = ((float) lettercount / (float) wordcount) * 100; // index L formula

    float S = ((float) sentencecount / (float) wordcount) * 100; // index S formula

    float index = (0.0588 * L) - (0.296 * S) - 15.8; // index formula

    int grade = round(index); // rounding index for the nearest int

    printf("Grade %i\n", grade);

    if (grade < 1) //if index number is less than 1 display Before Grade 1
    {
        printf("Before Grade 1\n");
    }
    if (grade > 16) //if index number is greater than 16 display Grade 16+
    {
        printf("Grade 16+\n");
    }

}