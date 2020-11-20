#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //int in which the key will be stored if valid
    int key = 0;  
        
    if (argc == 2)
    {
        string s = argv[1];
        
        //initialaziong the int detecting an error in the key
        int e = 0;
        
        //check the content of the key entered
        for (int i = 0; i < strlen(s); i++)
        {
            //if number increment a variable x
            if (s[i] >= '0' && s[i] <= '9')
            {
                key++;  
            }
            //if something else than a number increment e
            else
            {
                e++;
            }
        }
        //error printed if the code contains something else than a number
        if (e != 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        //convert the string into an integer
        else 
        {
            key = atoi(argv[1]);
        }
        printf("Current key: %i\n", key);
    }
    else 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if islower(plaintext[i])
        {
            printf("%c", (((plaintext[i] + key) - 'a') % 26) + 'a');
        }
        else if isupper(plaintext[i])
        {
            printf("%c", (((plaintext[i] + key) - 'A') % 26) + 'A');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}