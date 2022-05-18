//Shaun Comino
//Dr. Steinberg
//COP3223 Section 5
//Large Program 3

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 40

void rules(void); //display rules of the game
void maskWord (char starword[], int size); //mask the word with stars to display to user in game
int playRound(char starword[], char answer[]); //function that plays a round of hangman.
// returns 1 if user won
int occurancesInWord(char userguess, char answer[]); //number of times letter occurs in
// word. Greater than 0 means letter exist
void updateStarWord(char starword[], char answer[], char userguess); //update starword.
// replace respective * character with respective letter
void playAgain(int *play); //ask user if to play again. 1 is yes 2 is no


int main(void)
{

    // Delcaring file pointer
    FILE * fp;
    fp = fopen("words.txt", "r");

    // Declaring the answer and starred word (***)
    char answer[SIZE];
    char starword[SIZE];

    // Display the rules
    rules();

    int yes_or_no = 1;
    do
    {
        // Scanning the (nth iteration + 1) word of the txt file
        fscanf(fp, "%s", answer);
        int size = strlen(answer);

        // Makes the asterisked word of length strlen(answer)
        maskWord(starword, size);

        // Returns 1 if user won, 0 if not.
        int result = playRound(starword, answer);
        if (result == 1)
            printf("Congratulations! You won! The word was %s\n", answer);
        else
            printf("Sorry you did not win the round. The word was %s.\n", answer);

        // Prompts the user if they would like to play again
        playAgain(&yes_or_no);

    } while (yes_or_no != 2);

    // Closes program file access
    fclose(fp);

    printf("Thank you for playing today!\n");

    return 0;
}

void rules(void)
{
    // Prints greetings
    printf("Welcome to the Hangman Game!\n");
    printf("************************************************************************\n");
    printf("Here are the rules.\n");
    printf("I will provide you a set of * characters for each round.\n");
    printf("Each * represents a letter in the English Alphabet.\n");
    printf("You must figure out each letter of the missing word.\n");
    printf("For every correct letter guessed, I will reveal its place in the word.\n");
    printf("Each mistake will result in a strike.\n");
    printf("6 strikes will result in a loss that round.\n");
    printf("Are you ready? Here we go!\n");
    printf("************************************************************************\n");
}

void playAgain(int *play)
{
    // Prompts to play again
    printf("************************************************************************\n");
    printf("Would you like to play another round?\n");
    printf("1: Yes\n");
    printf("2: No\n");
    printf("Choice: ");
    scanf("%d", play);
    printf("\n");
    printf("************************************************************************\n");
}

void maskWord(char starword[], int size)
{
    // Makes a string of asterisks of length: size
    for (int i = 0; i < size; ++i)
    {
        starword[i] = '*';
        starword[i + 1] = '\0';
    }
}

int playRound(char starword[], char answer[])
{
    // Declaring variables
    int strikes = 0;
    int size = strlen(answer);
    char guessed_letters[SIZE];
    guessed_letters[0] = '\0';
    char guess;

    // This is needed to keep track of where to
    // add the next character in "guessed_letters"
    int total_guesses = 0;

    printf("Welcome to the Round!\n");
    printf("The size of the word has %d letters.\n\n", size);

    // Breaks out of loop upon reaching 6 strikes
    while (strikes < 6)
    {

        printf("You currently have %d strike(s).\n", strikes);
        printf("Letter(s) you have guessed: %s\n\n", guessed_letters);

        printf("%s\n\n", starword);

        printf("Enter your guess: ");
        scanf(" %c", &guess);

        // Handles uppercase input
        guess = tolower(guess);

        // Casts char guess into int
        int alph_check = (int)guess;

        // Checks if guess is in the alphabet
        if (!(guess >= 97 && guess <= 122))
        {
            printf("\nYou did not enter a letter from the alphabet.\n\n");
        }
        else
        {
            // Adds to guessed_letter string
            guessed_letters[total_guesses + 1] = '\0';
            guessed_letters[total_guesses] = guess;
            total_guesses++;

            printf("\n");

            // Checks how many times the letter occurs in the "answer" word
            int occurances = occurancesInWord(guess, answer);

            if (occurances == 0)
            {
                // Increments strikes if the user guessed incorrectly
                printf("The letter %c is NOT in the word.\n\n", guess);
                strikes++;
            }
            else
            {
                // For every occurance of guess in answer, reveal guess in starword
                updateStarWord(starword, answer, guess);
                int result = strcmp(starword, answer);
                if (result == 0)
                {
                    // User wins!
                    return 1;
                }
                printf("The letter %c is in the word.\n\n", guess);

            }
        }
    }
    printf("************************************************************************\n");
    return 0;
}

int occurancesInWord(char userguess, char answer[])
{
    // Calculates how many times guess occurs in answer
    int size = strlen(answer);
    int occurances = 0;
    for (int i = 0; i < size; ++i)
    {
        if (answer[i] == userguess)
            occurances++;
    }
    return occurances;
}

void updateStarWord(char starword[], char answer[], char userguess)
{
    int size = strlen(answer);

    // Reveals the guessed letter in the starred word.
    for (int i = 0; i < size; ++i)
    {
        if (answer[i] == userguess)
        {
            starword[i] = userguess;
        }
    }
}



