//Name: Shaun Comino
//Dr. Steinberg
//COP3502 Spring 2022
//Programming Assignment 3 Skeleton

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
card_t * insertBackDeck(card_t *head, card_t *node); //place card at end of pile
int compareCard(card_t * cardp1, card_t * cardp2); //compare cards
card_t * moveCardBack(card_t * head); //place card at top of deck to the bottom of the deck
card_t * randomizeDeck(card_t * head); //randomize the order of the deck given the head
card_t * war_scenario(card_t * player1_draw, card_t * player2_draw); //simluates the war scenario

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
    card_t *head = openCardDeck();

    head = randomizeDeck(head);

    card_t * player1_head = head;
    card_t * player2_head = search(head, (deckSize(head) / 2));

    card_t *split_deck_card = search(head, (deckSize(head) / 2) - 1);
    split_deck_card->nextptr = NULL;

    card_t * current_card = player1_head;
//    printf("\n\nPlayer 1's deck\n\n\n");
//    while (current_card != NULL)
//    {
//        printf("%s \n", current_card->type);
//        current_card = current_card->nextptr;
//    }

//    printf("\n\nPlayer 2's deck\n\n\n");
//    current_card = player2_head;
//    while (current_card != NULL)
//    {
//        printf("%s \n", current_card->type);
//        current_card = current_card->nextptr;
//    }

    card_t * player1_draw;
    card_t * player2_draw;

    while(deckSize(player1_head) > 0 && deckSize(player2_head) > 0)
    {
        player1_draw = player1_head;
        player2_draw = player2_head;


        int result = compareCard(player1_draw, player2_draw);
        printf("Player 1 pulled out %s. \t ", player1_draw->type);
        printf("Player 2 pulled out %s.\n", player2_draw->type);

        if (result == 1)
        {
            printf("Player 1 won that round.\n");
            player1_head = moveCardBack(player1_head);
            player1_head = insertBackDeck(player1_head, copyCard(player2_draw));
            player2_head = removeCard(player2_head, 0);
        }
        else if (result == 2)
        {
            printf("Player 2 won that round.\n");
            player2_head = moveCardBack(player2_head);
            player2_head = insertBackDeck(player2_head, copyCard(player1_draw));
            player1_head = removeCard(player1_head, 0);
        }
        else if (result == 0)
        {


            card_t * victory_list = NULL;
            int result = compareCard(player1_head, player2_head);
            card_t * p1_next_card = player1_head;
            card_t * p2_next_card = player2_head;

            while (result == 0)
            {
                printf("Ugh oh...We have a tie! W-A-R!\n");
                card_t * current_card = player1_head;

                int p1_card_count = 0;
                while (p1_next_card->nextptr != NULL && p1_card_count <= 3)
                {
                    victory_list = insertBackDeck(victory_list, copyCard(p1_next_card));
                    p1_next_card = removeCard(p1_next_card, 0);
                    p1_card_count++;
                }

                int p2_card_count = 0;
                while (p2_next_card->nextptr != NULL && p2_card_count <= 3)
                {
                    victory_list = insertBackDeck(victory_list, copyCard(p2_next_card));
                    p2_next_card = removeCard(p2_next_card, 0);
                    p2_card_count++;
                }
                printf("Player 1 pulled out %s. \t ", player1_draw->type);
                printf("Player 2 pulled out %s.\n", player2_draw->type);

                result = compareCard(p1_next_card, p2_next_card);

            }
            printf("Player %d won that W-A-R!\n", result);
            victory_list = insertBackDeck(victory_list, copyCard(p1_next_card));
            victory_list = insertBackDeck(victory_list, copyCard(p2_next_card));

            if (p2_next_card->nextptr != NULL)
                p2_next_card = removeCard(p2_next_card, 0);
            if (p1_next_card->nextptr != NULL)
                p1_next_card = removeCard(p1_next_card, 0);

            card_t * current_card;

            if (result == 1)
            {
                current_card = p1_next_card;
                while (current_card->nextptr != NULL)
                    current_card = current_card->nextptr;
                current_card->nextptr = victory_list;

            } else if (result == 2)
            {

                current_card = p2_next_card;
                while (current_card->nextptr != NULL)
                    current_card = current_card->nextptr;
                current_card->nextptr = victory_list;
            }

            player1_head = p1_next_card;
            player2_head = p2_next_card;

        }
        printf("Player 1 has %d cards.\n", deckSize(player1_head));
        printf("Player 2 has %d cards.\n", deckSize(player2_head));
        if (deckSize(player1_head) == 0)
            return 2;
        else if (deckSize(player2_head) == 0)
            return 1;

    }


}

card_t * randomizeDeck(card_t *head)
{
    card_t *rand_deck_head = NULL;
    int current_deck_size = deckSize(head);

    for (int i = 0; i < 52; i++)
    {
        int rand_card_int = rand() % current_deck_size;
        card_t *rand_card = search(head, rand_card_int);
        rand_deck_head = insertBackDeck(rand_deck_head, copyCard(rand_card));
        head = removeCard(head, rand_card_int);
        current_deck_size--;
    }

    return rand_deck_head;
}

void rules()
{
	printf("Welcome to the card game war!\n");
	printf("Here are the rules.\n");
	printf("You have a pile of cards and I have a pile of cards.\n");
	printf("We will each pull the top card off of our respective deck and compare them.\n");
	printf("The card with the highest number will win the round and take both cards.\n");
	printf("However if there is a tie, then we have to we have to place three cards out and pull one more to compare the final result.\n");
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
    if (empty(head))
        return 0;
    card_t *current_card = head;
    int card_count = 0;
    while (current_card != NULL)
    {
        current_card = current_card->nextptr;
        card_count++;
    }
    return card_count;
}

card_t * copyCard(card_t * node)
{
    card_t *copied_card = (card_t *) malloc (sizeof(card_t) * 1);

    char * type = (char *) malloc(sizeof(char) * 20);

    if (copied_card == NULL || type == NULL)
    {
        printf("Error in malloc...\n");
        exit(1);
    }
    strcpy(type, node->type);
    copied_card->type = type;
    copied_card->rank = node->rank;
    copied_card->nextptr = node->nextptr;

    return copied_card;
}

card_t * search(card_t * node, int spot)
{
    card_t *current_card = node;
    for (int i = 0; i < spot; i++)
        current_card = current_card->nextptr;

    return current_card;
}

card_t * removeCard(card_t * node, int spot)
{

    if (node->nextptr == NULL || spot == 0)
    {
        card_t *new_head = node->nextptr;
        free(node->type);
        free(node);
        return new_head;
    }
    card_t *current_card = node;

    for (int i = 0; i < spot - 1; i++)
        current_card = current_card->nextptr;


    card_t *temp = current_card->nextptr;
    current_card->nextptr = current_card->nextptr->nextptr;
    free(temp->type);
    free(temp);
    return node;

}

card_t * insertBackDeck(card_t *head, card_t *node)
{
    if (empty(head))
    {
        node->nextptr = NULL;
        return node;
    }
    card_t *current_card = head;
    while (current_card->nextptr != NULL)
        current_card = current_card->nextptr;
    card_t *last_card = current_card;
    last_card->nextptr = node;
    last_card->nextptr->nextptr = NULL;
    return head;

}

int compareCard(card_t * cardp1, card_t * cardp2)
{

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
    card_t *new_head = head->nextptr;

    card_t *current_card = head;
    while (current_card->nextptr != NULL)
        current_card = current_card->nextptr;
    current_card->nextptr = head;
    current_card->nextptr->nextptr = NULL;
    return new_head;
}

void cleanUp(card_t * head)
{
    card_t *card = head;
    while(card != NULL)
    {
        card_t *temp = card;
        card = card->nextptr;
        free(temp->type);
        free(temp);
    }

}
int empty(card_t * node)
{
	return (node == NULL); //return condition result
}
