#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");

    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i]) == 0)
        {
            ranks[rank]=i;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(ranks[i] == j)
            {
                for(int a = i+1; a < candidate_count; a++)
                {
                    preferences[j][ranks[a]] += 1;
                }
                break;
            }
        }
    }
    //printf(" %d %d %d ", preferences[0][0],preferences[0][1],preferences[0][2]);
    //printf("\n");
    //printf(" %d %d %d", preferences[1][0],preferences[1][1],preferences[1][2]);
    //printf("\n");
    //printf(" %d %d %d", preferences[2][0],preferences[2][1],preferences[2][2]);
    //printf("\n");

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        for( int j = i; j < candidate_count; j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            if(preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    //printf("%i \n", pair_count);
    //printf(" %i %i %i %i %i %i", pairs[0].winner,pairs[0].loser, pairs[1].winner, pairs[1].loser,pairs[2].winner, pairs[2].loser);

    
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair max[MAX] =  {pairs[0]};
    int schet = -1;
    int d1;
    int d2;
    do
    {
        for(int i = 0; i < pair_count-1; i++)
        {   
            schet=0;
            d1 = preferences[pairs[i].winner][pairs[i].loser]-preferences[pairs[i].loser][pairs[i].winner];
            d2 = preferences[pairs[i+1].winner][pairs[i+1].loser]-preferences[pairs[i+1].loser][pairs[i+1].winner];
            
            if(d1 < d2)
            {
               max[0]=pairs[i+1];
               pairs[i+1]=pairs[i];
               pairs[i]=max[0];
               schet += 1;
            }
        }
    }
    while(schet!=0);
    
    //printf("\n %i \n", pair_count);
    //printf(" %i %i %i %i %i %i", pairs[0].winner,pairs[0].loser, pairs[1].winner, pairs[1].loser,pairs[2].winner, pairs[2].loser);
  
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    bool iftrue = false;
    pair second[0];
    pair third[0];
    
    for(int f1  = 0; f1 < candidate_count; f1++)
    {
        for(int f2 = 0; f2 < candidate_count; f2++)
        {
            locked[f1][f2] = false;
        }
    }
    
    for(int i = 0; i < pair_count; i++)
    {
        iftrue = false;
        
        for (int j = 0; j < pair_count; j++)
        {
            if(pairs[j].winner == pairs[i].loser)
            {
                if (i != j)
                second[0] = pairs[j];
            }
            
            if(pairs[j].loser == pairs[i].winner)
            {
                if(i !=j)
                third[0] = pairs[j];
            }
        }
        
        if((locked[pairs[i].loser][second[0].loser] == true) && (locked[third[0].winner][pairs[i].winner] == true))
        {
            if(i == pair_count - 1)
            {
                return;
            }
            
            else
            {
                iftrue = true;
            }
        }
    
        
        if(iftrue == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    
   //printf(" %d %d %d ", locked[0][0],locked[0][1],locked[0][2]);
   // printf("\n");
   // printf(" %d %d %d  ", locked[1][0],locked[1][1],locked[1][2]);
   // printf("\n");
   // printf(" %d %d %d  ", locked[2][0],locked[2][1],locked[2][2]);
    //printf("\n");
    return;
}

// Print the winner of the election
void print_winner(void)
{

    // TODO
    for(int j = 0; j < candidate_count; j++)
    {
        for(int i = 0; i < candidate_count; i++)
        {
            if(locked[i][j] == true)
            break;
            
            else
            {
                if(i == candidate_count-1)
                {
                    printf("%s", candidates[j]);
                    return;
                }
            }
            

        }
    }
    return;
}

