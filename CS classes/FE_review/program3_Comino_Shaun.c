//Name: Shaun Comino
//Dr. Steinberg
//COP3502 Spring 2022
//Programming Assignment 3

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct card_s{
	int rank;    //number
	char * type; //type of card
	struct card_s * nextptr;
}card_t;

//function prototypes
void rules(); //display rules
int playRound(); //simulate round
card_t * openCardDeck(); //open the card deck and place into a linkedlist setup
card_t * insertBackSetup(card_t *node, char *name, int cardrank); //take card from orginial deck and place in back of linked list for setup of game
int empty(card_t * node); //check to see if linked list is empty
void cleanUp(card_t * head); //free memory to prevent memory leaks
int deckSize(card_t * head); //count number of nodes in the linked list
card_t * search(card_t * node, int spot); //search list for a specific spot in the card deck indexing is similar to array setup
card_t * copyCard(card_t * node); //make a deep copy of card
card_t * removeCard(card_t * node, int spot); //remove card from linkedlist
card_t * insertBackDeck(card_t * head, card_t *node); //place card at end of pile
int compareCard(card_t * cardp1, card_t * cardp2); //compare cards
card_t * moveCardBack(card_t * head); //place card at top of deck to the bottom of the deck
card_t * randomizeDeck(card_t * head); //randomize the order of the deck given the head

int main()
{
	int seed;
	printf("Enter Seed: ");
	scanf("%d", &seed);

	srand(seed); //seed set
	rules();

	int player; //1 or 2
	int result;

	printf("Would you like to be player 1 or 2?\n");
	printf("Enter 1 or 2: ");
	scanf("%d", &player); //choose player

	for(int game = 1; game <= 5; ++game) //simulate games
	{
		printf("Alright lets play game %d.\n", game);
		printf("Lets split the deck.\n");

		result = playRound(); //play game

		if((result == 1 && player == 1) || (result == 2 && player == 2)) //determine who won
			printf("You won game %d.\n", game);
		else
			printf("I won game %d.\n", game);
	}

	return 0;
}

int playRound()
{
    // Initialize the sorted card deck into a linked list
    card_t * head = openCardDeck();

    // Result should print 52 if initialized properly
    printf("There are %d cards in the deck.\n", deckSize(head));

    // Initialize the player decks
    card_t * player1_head = NULL;
    card_t * player2_head = NULL;

    // Declare size that will change during while loop runtime
    int current_deck_size = deckSize(head);

    // While there are still cards in the deck
    while (current_deck_size > 0)
    {
       // Pick a number [0, 52] inclusize
       int rand_card_spot = rand() % current_deck_size;

       // Copy the card at that spot into a fresh linked list node
       card_t * random_card = copyCard(search(head, rand_card_spot));

       // Depending on current_deck_size, assign the copied card to
       // either player 1 or player 2
       if (current_deck_size % 2 == 1)
       {
           // Insert to back of player 1 list
           player1_head = insertBackDeck(player1_head, random_card);

           // Remove the original card from the original linked list
           head = removeCard(head, rand_card_spot);

           // Since a card was just removed, decrement deck size
           current_deck_size--;
       } else if (current_deck_size % 2 == 0)
       {
           // Insert to back of player 2 list
           player2_head = insertBackDeck(player2_head, random_card);

           // See above conditional control structure
           head = removeCard(head, rand_card_spot);
           current_deck_size--;
       }
    }


    while(deckSize(player1_head) > 0 && deckSize(player2_head) > 0)
    {


        // Compare the two based on their ranking
        int result = compareCard(player1_head, player2_head);

        // Print the pulled card types
        printf("Player 1 pulled out %s. \t", player1_head->type);
        printf(" Player 2 pulled out %s.\n", player2_head->type);

        // Handle player 1 comparison victory
        if (result == 1)
        {

            printf("Player 1 won that round.\n");
            player1_head = moveCardBack(player1_head);
            player1_head = insertBackDeck(player1_head, copyCard(player2_head));
            player2_head = removeCard(player2_head, 0);
        }

        // Handle player 2 comparison victory
        else if (result == 2)
        {

            printf("Player 2 won that round.\n");
            player2_head = moveCardBack(player2_head);
            player2_head = insertBackDeck(player2_head, copyCard(player1_head));
            player1_head = removeCard(player1_head, 0);
        }
        // Handle a tie. W-A-R scenario...
        // while loop (result)
        // Sufficient cards scenario
        // insufficient cards scenario
        else if (result == 0)
        {
            // Initialize a fresh linked list that will contain
            // all the won cards
            card_t * victory_list = NULL;

            // Compare again just in case
            int result = compareCard(player1_head, player2_head);


            int tie_count = 1;
            // While loop handling successive ties (result stays == 0)
            while (result == 0)
            {

                // Matching the printing format in sample output
                if (tie_count > 1)
                {
                    printf("Player 1 has %d cards.\n", deckSize(player1_head));
                    printf("Player 2 has %d cards.\n", deckSize(player2_head));
                }

                if (deckSize(player1_head) == 1)
                {
                    player2_head = insertBackDeck(player2_head, copyCard(player1_head));
                    free(player1_head->type);
                    free(player1_head);
                    player1_head = NULL;
                    return 2;

                } else if (deckSize(player2_head) == 1)
                {
                    player1_head = insertBackDeck(player1_head, copyCard(player2_head));
                    free(player2_head->type);
                    free(player2_head);
                    player2_head = NULL;
                    return 1;

                } else if (deckSize(player1_head) == 2 || deckSize(player2_head) == 2)
                {
                    // Insert player 1 face up
                    victory_list = insertBackDeck(victory_list, copyCard(player1_head));
                    player1_head = removeCard(player1_head, 0);

                    // Insert player2 face up
                    victory_list = insertBackDeck(victory_list, copyCard(player2_head));
                    player2_head = removeCard(player2_head, 0);
                }
                else
                {
                    // Insert player1 face up
                    victory_list = insertBackDeck(victory_list, copyCard(player1_head));
                    player1_head = removeCard(player1_head, 0);

                    // Insert player1 face down
                    victory_list = insertBackDeck(victory_list, copyCard(player1_head));
                    player1_head = removeCard(player1_head, 0);

                    // Insert player2 face up
                    victory_list = insertBackDeck(victory_list, copyCard(player2_head));
                    player2_head = removeCard(player2_head, 0);

                    // Insert player2 face down
                    victory_list = insertBackDeck(victory_list, copyCard(player2_head));
                    player2_head = removeCard(player2_head, 0);
                }

                printf("Ugh oh...We have a tie! W-A-R!\n");

                // Handle printing successive ties
                printf("Player 1 pulled out %s. \t", player1_head->type);
                printf(" Player 2 pulled out %s.\n", player2_head->type);

                // Update the result for while loop header
                result = compareCard(player1_head, player2_head);
                tie_count++;

            }


            // Finally, insert the last drawn cards
            victory_list = insertBackDeck(victory_list, copyCard(player1_head));
            victory_list = insertBackDeck(victory_list, copyCard(player2_head));


            // Remove the just drawn cards from the original lists
            player1_head = removeCard(player1_head, 0);
            player2_head = removeCard(player2_head, 0);

            // Declare iterator card_t
            card_t * current_card;

            // Append won cards to winning player list
            if (result == 1)
            {
                printf("Player %d won that W-A-R!\n", result);
                if (player1_head != NULL)
                {
                    current_card = player1_head;

                    // Iterate until at the end of player 1 list
                    // and append victory_list
                    while (current_card->nextptr != NULL)
                        current_card = current_card->nextptr;
                    current_card->nextptr = victory_list;
                } else if (player1_head == NULL)
                {
                    player1_head = victory_list;
                }

            } else if (result == 2)
            {

                printf("Player %d won that W-A-R!\n", result);
                if (player2_head != NULL)
                {
                    // Iterate until at the end of player 2 list
                    // and append victory_list
                    current_card = player2_head;
                    while (current_card->nextptr != NULL)
                        current_card = current_card->nextptr;
                    current_card->nextptr = victory_list;
                } else if (player2_head == NULL)
                {
                    player2_head = victory_list;
                }

            }


        }

        // Re-display the amount of cards each player had
        printf("Player 1 has %d cards.\n", deckSize(player1_head));
        printf("Player 2 has %d cards.\n", deckSize(player2_head));

        // In the case that either player wins...
        // winning defined as the other player having
        // no more cards left ( cards == 0 )
        if (deckSize(player1_head) == 0)
            return 2;
        else if (deckSize(player2_head) == 0)
            return 1;
    }

    // Deallocate memory used for player 1 and player 2 linked lists
    cleanUp(player1_head);
    cleanUp(player2_head);
    cleanUp(head);
}


void rules()
{
	printf("Welcome to the card game war!\n");
	printf("Here are the rules.\n");
	printf("You have a pile of cards and I have a pile of cards.\n");
	printf("We will each pull the top card off of our respective deck and compare them.\n");
	printf("The card with the highest number will win the round and take both cards.\n");
	printf("However if there is a tie, then we have to we have to place one card faced down and the next one faced up and compare the results.\n");
	printf("Winner of the tie, will grab all the cards out. However if it's a tie again, then we repeat the same action.\n");
	printf("Ready? Here we go!\n");
}

card_t * openCardDeck()
{
	FILE *fptr = fopen("deck.txt", "r");

	char *name = (char *) malloc(sizeof(char) * 20);

	if (name == NULL)
	{
		printf("Error in malloc...\n");
		exit(1);
	}

	card_t * head = NULL;

	int cardrank = 13;
	int tracker = 1;
	while(fscanf(fptr, "%s", name) == 1)
	{
		strcat(name, " ");

		if(tracker % 5 == 1)
		{
			strcat(name, "of Clubs");
			head = insertBackSetup(head, name, cardrank);
		}
		else if(tracker % 5 == 2)
		{
			strcat(name, "of Diamonds");
			head = insertBackSetup(head, name, cardrank);
		}
		else if(tracker % 5 == 3)
		{
			strcat(name, "of Hearts");
			head = insertBackSetup(head, name, cardrank);
		}
		else if(tracker % 5 == 4)
		{
			strcat(name, "of Spades");
			head = insertBackSetup(head, name, cardrank);
			tracker = 0;
			--cardrank;
		}

		++tracker;

	}

	free(name);
	fclose(fptr);

	return head;
}

card_t * insertBackSetup(card_t *node, char *name, int cardrank)
{

    if(empty(node)) //check to see if list is empty
    {
		node = (card_t *) malloc(sizeof(card_t));

		if(empty(node)) //check to see if malloc worked
		{
			printf("Did not allocate head successfully...");
			printf("Program Terminating...\n");
			exit(1);
		}
		else //otherwise populate data of new head node
		{
			node->type = (char *) malloc(sizeof(char) * 20);

			if(node->type == NULL)
			{
				printf("Error with malloc...\n");
				exit(1);
			}

			strcpy(node->type, name);
			node->rank = cardrank;
			node->nextptr = NULL; //must make new tail nextptr NULL!!!

			return node;  //terminate
		}

    }

	//here we know that the list has at least one node

	card_t *head = node; //keep pointer to head since we will need to return this address

	while(node->nextptr != NULL) //traverse to tail
		node = node->nextptr;

	node->nextptr = (card_t *) malloc(sizeof(card_t));

	if(node->nextptr == NULL) //see if new tail was allocated successfully
	{
		printf("Did not allocate node successfully...");
		return head; //terminate if tail didn't get created
	}

	//populate new node
	node->nextptr->type = (char *) malloc(sizeof(char) * 20);

	if(node->nextptr->type == NULL)
	{
		printf("Error with malloc...\n");
		exit(1);
	}

	strcpy(node->nextptr->type, name);
	node->nextptr->rank = cardrank;
	node->nextptr->nextptr = NULL; //very important

	return head; //return head node since we need our starting point of the linked list
}

int deckSize(card_t * head)
{
    // Return 0 if there isn't a linked list
    if (empty(head))
        return 0;

    // Declare iterator card
    card_t * current_card = head;
    int card_count = 0;

    // != NULL because it needs to see every card
    // current_card->nextptr != NULL would return
    // 1 less than the amount of nodes in the list
    while (current_card != NULL)
    {
        // Assign to nextptr
        current_card = current_card->nextptr;
        card_count++;
    }

    return card_count;
}

card_t * copyCard(card_t * node)
{
    // Allocate memory for the new card
    card_t * copied_card = (card_t *) malloc (sizeof(card_t) * 1);

    // Allocate space for the dynamic string for the card name
    char * type = (char *) malloc(sizeof(char) * 20);

    // malloc() error handling
    if (copied_card == NULL || type == NULL)
    {
        printf("Error in malloc...\n");
        exit(1);
    }

    // Copy old card string into freshly allocated dynamic string
    strcpy(type, node->type);
    copied_card->type = type;

    // Copy the rank
    // No need for allocation because it's just an integer
    copied_card->rank = node->rank;
    copied_card->nextptr = node->nextptr;

    // Return the copied version without having edited the original
    return copied_card;
}

card_t * search(card_t * node, int spot)
{
    // Simple linear search for a card in the given linked list
    // at "index" of "spot"

    // Iterator node
    card_t * current_card = node;

    // For loop because it's assumed that the card exists
    // if it's being passed "spot"
    for (int i = 0; i < spot; i++)
        current_card = current_card->nextptr;

    // Return the found card
    return current_card;
}

card_t * removeCard(card_t * node, int spot)
{

    if (node->nextptr == NULL || spot == 0)
    {
        card_t * new_head = node->nextptr;
        // Frees the string because it was dynamically allocated.
        // Also deallocates the node itself
        free(node->type);
        free(node);

        return new_head;
    }

    // Iterator node
    card_t * current_card = node;

    // For loop because it's assumed that card exists
    // if it's passed an integer of "spot"
    for (int i = 0; i < spot - 1; i++)
        current_card = current_card->nextptr;


    // Switching the pointers to break the connection from
    // the node desired to be removed
    card_t *temp = current_card->nextptr;

    // Tricky pointer manipulation that doesn't require
    // accounting for the last node needing to be removed
    current_card->nextptr = current_card->nextptr->nextptr;

    // Deallocate
    free(temp->type);
    free(temp);

    return node;

}

card_t * insertBackDeck(card_t *head, card_t *node)
{
    // In case there is no linked list
    if (empty(head))
    {
        node->nextptr = NULL;
        return node;
    }

    // Iterator node
    card_t * current_card = head;

    // Get to the last node
    while (current_card->nextptr != NULL)
        current_card = current_card->nextptr;

    // Insert the new card into the back
    card_t * last_card = current_card;
    last_card->nextptr = node;

    // Assign the new last pointer's nextptr to NULL
    last_card->nextptr->nextptr = NULL;

    return head;

}

int compareCard(card_t * cardp1, card_t * cardp2)
{
    // Return an integer value based on comparing
    // each card's rankings
    if (cardp1->rank > cardp2->rank)
        return 1;
    else if (cardp2->rank > cardp1->rank)
        return 2;
    else if (cardp2->rank == cardp1->rank)
        return 0;
    printf("Something went wrong comparing the two...\n");

}

card_t * moveCardBack(card_t *head)
{
    // In case there is one item in linked list
    if (head->nextptr == NULL)
        return head;

    // Change head to the next one in the list
    card_t * new_head = head->nextptr;

    // Iterator node
    card_t * current_card = head;

    // Traverse to the last node
    while (current_card->nextptr != NULL)
        current_card = current_card->nextptr;

    // Shifting front to back
    current_card->nextptr = head;
    current_card->nextptr->nextptr = NULL;
    return new_head;
}

void cleanUp(card_t * head)
{
    card_t * card = head;
    while(card != NULL)
    {
        card_t * temp = card;
        card = card->nextptr;
        free(temp->type);
        free(temp);
    }

}
int empty(card_t * node)
{
	return (node == NULL); //return condition result
}
