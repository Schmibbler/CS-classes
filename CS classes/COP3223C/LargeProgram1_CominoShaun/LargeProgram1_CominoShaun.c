//Shaun Comino
//Dr. Steinberg
//COP 3223 Section 5
//Large Program 1

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


void Greeting(); //display welcome message to user
void SetSeed(int seed); //set the seed of pseudo random generator
int PlayRound(char answer, int round); //play one round
char GetGuess(); //retrieve the user's guess
int CompareLetters(char guess, char answer); //compare the user's guess with the answer
void RoundResult(int result, char answer); //determine if the user won or loss the round

int main()
{
    Greeting();
    SetSeed(3);

	for (int game = 1; game <= ROUNDS; game++)
	{
	    int charInt;

	    // Picks a random number from [65, 90]
	    // [65, 90] is A to Z in ASCII terms
	    charInt = rand() % (26) + 65;

	    // Casts the random integer to an uppercase letter
	    char answer = (char) charInt;

	    int result;

	    // Plays a round, records the result
        result = PlayRound(answer, game);

        // Uses 'result' to determine if the round was won
	    RoundResult(result, answer);
	}

	return 0;
}

void Greeting()
{
    // Greets the user
    printf("********************************************************\n");
    printf("Welcome to the Letter Guessing Game!\n");
    printf("Here are the rules.\n");
    printf("I will think of a letter in the English Alphabet and you will have to guess it!\n");
    printf("I will provide you a limit of 5 chances to guess the correct the letter.\n");
    printf("Are you ready to play 5 rounds? Here we go!\n");
    printf("********************************************************\n");
    printf("********************************************************\n");
}

void SetSeed(int seed)
{
    // Sets the seed for rand() function
    srand(seed);
}

int CompareLetters(char guess, char answer)
{
    // Casts 'guess' and 'answer' to integer type
    guess = (int)guess;
    answer = (int)answer;

    /*
    Uses <ctype.h> library islower() function
    to check if 'guess' is lowercase
    */
    if (islower(guess))
    {
        // If it is, make it uppercase
        guess = toupper(guess);
    }

    int guessResult;

    // Stores distance from 'guess' and 'answer' on a number line
    // Negative 'guessResult' value means the letter comes before,
    // and positive means after
    guessResult = answer - guess;

    /*
    Checks guessResult value to see if it's equal to 0;
    in which case there is 0 distance between 'answer'
    and guess, meaning they are equal.
    */
    if (guessResult == 0)
    {
        // Similar to int main() function, returns 0 if it works
        // Essentially 0 is a placeholder "True" value.
        return 0;
    }

    else if (guessResult < 0)
    {
        printf("I am thinking of a letter that comes before your guess\n\n");
        return 1;
    }

    else if (guessResult > 0)
    {
        printf("I am thinking of a letter that comes after your guess\n\n");
        return 1;
    }


}

void RoundResult(int result, char answer)
{
    // Records and outputs round result
    if (result == 0)
    {
        printf("You guessed %c!\n", answer);
        printf("Congratulations, that\'s the letter I was thinking of!\n");
        printf("********************************************************\n\n");
    }

    else if (result == 1)
    {
        printf("You lost the round,\n");
        printf("The correct answer was %c\n\n", answer);
    }
}

// Returns integer 0 upon a correct guess
int PlayRound(char answer, int round)
{
	printf("Round %d\n", round);

	for (int chance = 1; chance <= 5; chance++)
	{
	    printf("Guess #%d: \n", chance);
	    char guess;

	    // Gets user's guess
	    guess = GetGuess();

        int guessResult;
        guessResult = CompareLetters(guess, answer);

        if (guessResult == 0)
        {
            // Same concept with CompareLetters();,
            // 0 basically means "True" or "It worked"
            return 0;
        }
	}
}

char GetGuess()
{
    // Assigns user input to 'guess' and returns it
    char guess;
    printf("Enter your guess: ");
    scanf(" %c", &guess);
    printf("\n");
    return guess;
}
