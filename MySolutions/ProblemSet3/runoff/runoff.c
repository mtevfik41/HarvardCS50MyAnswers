#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 9
#define MAX_VOTERS 100

int preferences[MAX_VOTERS][MAX_CANDIDATES]; // two dimensional array for tabulate

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate; // defining new datatype

candidate candidates[MAX_CANDIDATES]; // defining new varibles


// global variables
int voter_count;
int candidate_count;

// functions

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[]) // main code
{
    if (argc < 2) // checking for invalid usage
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }
    
    candidate_count = argc - 1; // populate array of candidates
    
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    
    voter_count = get_int("Number of voters: ");
    
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }
    
    for (int i = 0; i < voter_count; i++) // querying for votes
    {
        for (int j = 0; j < candidate_count; j++) // querying for each rank
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }
    
    while (true) // keep holding runoffs until winner exists
    {
        tabulate(); // calculate votes given remaining candidates
        
        bool won = print_winner();
        
        if (won) // check if election has been won
        {
            break;
        }
        int min = find_min();
        
        bool tie = is_tie(min);
        
        if (tie) // if tie, everyone wins
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            
            break;
        }
        eliminate(min); // eliminate anyone with minimum number of votes

        for (int i = 0; i < candidate_count; i++) // reset vote counts back to zero
        {
            candidates[i].votes = 0;
        }

    }
    return 0;
}


bool vote(int voter, int rank, string name) // voting function
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void tabulate(void) // tabulate votes for non-eliminated candidates
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes += 1;
                break;
            }
        }
    }
    return;
}

bool print_winner(void) // printing who is winner
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

int find_min(void) // finding the smallest vote number
{
    int minVotes = voter_count;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < minVotes)
        {
            minVotes = candidates[i].votes;
        }
    }
    return minVotes;
}

bool is_tie(int min) // tie situtation function
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min) // eliminate function
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}