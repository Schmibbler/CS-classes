//Shaun Comino
//Dr. Andrew Steinberg
//COP3502 Computer Science 1
//Programming Assignment 5 Solution

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 2000

typedef struct{
	char * name; //dynamic string
	int rank;
}player_t;

//function prototype(s)
player_t* scanRoster(player_t *roster);
void quickSort(player_t * arr, int p, int r);
int partition(player_t * arr, int p, int r);
void swapPlayers(player_t * p1, player_t * p2);
player_t copyPlayer(player_t * player);
void cleanUp(player_t * roster, int length);


int main(void)
{
	int seed;
	printf("Enter seed: ");
	scanf("%d", &seed);
	srand(seed);

	player_t *roster = (player_t*) malloc(sizeof(player_t) * MAX);

	roster = scanRoster(roster);

	// QUICKLY sort the roster FASTFASTFASTFAST
	quickSort(roster, 0, MAX - 1);
    //                    ^    ^ avoid out of bounds segfault

    double average1 = 0;
	double average2 = 0;

	// This only adds n/2 to the T(n) of the program
	// where n = the size of the roster
	// because it only sees half of the array
	for (int i = 0; i < 1000; i++)
    {
        // O(1) operation
        average1 += roster[i + 1000].rank;
        // Another O(1) operation
        average2 += roster[i].rank;
    }

    // Careful to use 1000.0 and not 1000
    // to avoid implicit casting to an int
    average1 /= 1000.0;
    average2 /= 1000.0;

    printf("Team 1 Rank Average is: %f\n", average2);
	printf("Team 2 Rank Average is: %f\n", average1);
	cleanUp(roster, MAX);
	free(roster);
	return 0;
}


player_t* scanRoster(player_t *roster)
{
	FILE *fptr = fopen("players.txt", "r");

	char name[20];
	int index = 0;

	while(fscanf(fptr, "%s", name) == 1)
	{
		roster[index].name = (char *) malloc(sizeof(char) * 20);
		strcpy(roster[index].name, name);
		roster[index].rank = rand() % 5 + 1;
		++index;
	}

	fclose(fptr);

	return roster;
}


void quickSort(player_t * arr, int p, int r)
{
    // Elegant quicksort solution:
    // After partitioning the arrays,
    // sort the left, then right subarrays
	if (p < r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}


// Partitioning helper function for quicksort
int partition(player_t * arr, int p, int r)
{
    // All structs left of x should be < x,
    // all structs right of x should be > x,
    // per quicksort rules
	player_t x = arr[r];

	int i = (p - 1);

	for (int j = p; j < r; j++)
	{
	    // Use the rank, not the names... duh
		if (arr[j].rank <= x.rank)
		{
			++i;
           player_t temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;
		}
	}

	// Make a temp player to swap the values of
	// arr[i + 1] and arr[r]
	player_t temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;

	return (i + 1);
}

void swapPlayers(player_t * p1, player_t * p2)
{
    player_t temp_player;
    strcpy(temp_player.name, p2->name);
    temp_player.rank = p2->rank;

    // Read from p1 data and write to p2 data
    strcpy(p2->name, p1->name);
    p2->rank = p1->rank;

    // Read from copied p2 and write to p1
    strcpy(p2->name, temp_player.name);
    p2->rank = temp_player.rank;

    // Free the temp player dynamic string
    // because it is no longer needed
    free(temp_player.name);
    // ^ no need to "free" the temp_player itself, because it
    // is not a pointer, and was not allocated with malloc()

}


// Deallocate all the dynamic name strings
void cleanUp(player_t * roster, int length)
{
    for (int i = 0; i < length; ++i)
        free(roster[i].name);
}
