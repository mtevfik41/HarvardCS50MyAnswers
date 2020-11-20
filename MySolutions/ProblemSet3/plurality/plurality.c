#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX 9

typedef struct // creating new datatype
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX]; // defining new variable

int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2) // usage explanation
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    
    candidate_count = argc - 1;
    if (candidate_count > MAX) // usage explanation
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < argc - 1; i++) // adding candidate name's
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    int voter_count = get_int("Number of voters: ");
    
    for (int i = 0; i < voter_count; i++) // voting section
    {
        string name = get_string("Vote: ");
        
        if (!vote(name))
        {
            printf("Invalid vote\n");
        }
    }
    print_winner();
}

bool vote(string name) // // Update vote totals given a new vote .function
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(candidates[i].name, name))
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}
void print_winner(void) // Print the winner of the election ./function
{
    int max_vote_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_vote_count)
        {
            max_vote_count = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_vote_count)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
