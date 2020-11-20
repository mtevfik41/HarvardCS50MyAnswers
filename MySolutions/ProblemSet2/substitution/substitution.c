#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void encrypt(string plain_text, string anahtar);

int main(int argc, string argv[]) // argv[1] should be the input anahtar.
{
    if (argc != 2)
    {
        printf("Usage: ./substitution anahtar\n"); // should only have two arguments.
        return 1;
    }

    string anahtar = argv[1];

    if (strlen(anahtar) < 26)
    {
        printf("anahtar must contain 26 characters.\n");
        return 1;
    }

    int sayim = 0; // sayim should be strlen(anahtar) (26) after completed iteration.

    for (int i = 0; i < strlen(anahtar); i++) // Loops 26 times.
    {

        for (int j = 0; j < strlen(anahtar); j++) // Loop will sayim twice if there is a repeated char.
        {
            if (anahtar[j] == anahtar[i])
            {
                sayim++;
            }
        }

        if (isalpha(anahtar[i]) == 0) // anahtar can only  have alphabetic characters.
        {
            printf("Usage: ./substitution anahtar\n");
            return 1;
        }
    }

    if (sayim != strlen(anahtar)) // If there is a repeated char, sayim will be more than strlen(anahtar) (26).
    {
        printf("anahtar cannot contain duplicate characters.\n");
        return 1;
    }

    string plain_text = get_string("plain_text: ");

    encrypt(plain_text, anahtar);

    return 0;
}

void encrypt(string plain_text, string anahtar)
{
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plain_text); i++)
    {
        for (int j = 0; j < strlen(anahtar); j++)
        {
            if (plain_text[i] == j + 'A') // First letter of anahtar represented by 'A'.
            {
                printf("%c", toupper(anahtar[j])); // If the position matches, print that corresponding letter in uppercase.
            }
            else if (plain_text[i] == j + 'A' + 32) // Convert anahtar into lowercase for position matching.
            {
                printf("%c", tolower(anahtar[j])); // Print the lowercase version if it matches.
            }
        }

        if (isalpha(plain_text[i]) == 0)
        {
            printf("%c", plain_text[i]); // Print commas, spaces, etc.
        }
    }

    printf("\n"); // New line before function ends.
}