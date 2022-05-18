//Shaun Comino
//Dr. Steinberg
//COP3223 Section 5
//Small Program 7

#include <stdio.h>
#include <string.h>
#define SIZE 30

void deblank(char *string, char *out_string);
const char* pluralize(char *string);
void fact(char *string);
char *substring(char *string, char *string2);

int main(void)
{

    // Question 1
    char string[SIZE];
    char out_string[SIZE];
    printf("Enter a string to remove whitespaces from: ");

    // fgets() is the most stable function for this use case
    fgets(string, SIZE, stdin);
    printf("\n");
    printf("Input String: %s", string);

    // Remove whitespaces function
    deblank(string, out_string);
    printf("Output String: %s", out_string);
    printf("\n\n");

    // Question 2
    printf("Enter a word to make plural: ");

    // Scanf, because it's only one word
    scanf("%s", string);
    printf("\n");

    // Copy the result of the function, which is a string
    strcpy(string, pluralize(string));
    printf("%s\n\n", string);

    // Question 3
    printf("Enter a word to see the first letter: ");

    // scanf() again because it's one word
    scanf("%s", string);
    printf("\n");
    fact(string);

    // Question 4
    printf("Enter the string to check within: ");

    // Collect input string to check within
    scanf("%s", string);
    printf("\n");

    // Collect input string to check for
    char string2[SIZE];

    printf("Enter the string you wish to find: ");
    scanf("%s", string2);
    printf("\n");

    // Evaluates the result of the function
    char *charptr = substring(string, string2);
    if (charptr == NULL)
    {
        printf("Word not found\n");
    }

    else
    {
        printf("The first occurence of this word begins at address %p\n", charptr);
    }

    return 0;
}

void deblank(char *string, char *out_string)
{

	int size = strlen(string) - 1;

	// Declare 2 iterator variables
	int i = 0;
	int j = 0;

	for (i; i < size; ++i)
    {
        // If the character at index i is not a space,
        // put that character into the new string
        if (string[i] != ' ')
        {
            string[j] = string[i];
            j++;
        }
    }

    // Sets last letter of string to '\0'
    // so C compiler can know where the string
    // ends
    string[j] = '\0';

    // Copy the result into the output string
    strcpy(out_string, string);
}

const char* pluralize(char *string)
{
    int length = strlen(string);

    // Declaring the last two letters of the string
    char last_letter = string[length - 1];
    char second_last = string[length - 2];

    // Declaring the indices of the last two characters
    int last_index = (length - 1);
    int sec_to_last_index = (length - 2);

    // There is no concise way to do this, really.
    // Switch-case is possible but is more obtuse
    // than a chain of if, else if, else statements
    if (last_letter == 'y')
    {

        string[last_index] = 'i';
        string[last_index + 1] = 'e';
        string[last_index + 2] = 's';
        string[last_index + 3] = '\0';

    }

    else if (second_last == 'c' && last_letter == 'h')
    {
        string[last_index + 1] = 'e';
        string[last_index + 2] = 's';
        string[last_index + 3] = '\0';
    }

    else if (second_last == 's' && last_letter == 'h')
    {
        string[last_index + 1] = 'e';
        string[last_index + 2] = 's';
        string[last_index + 3] = '\0';
    }

    else if (last_letter == 's')
    {
        string[last_index + 1] = 'e';
        string[last_index + 2] = 's';
        string[last_index + 3] = '\0';
    }

    else
    {
        string[last_index + 1] = 's';
        string[last_index + 2] = '\0';
    }

    // This function does cannot account for special cases in the
    // English language. For example: fish -> fishes which is incorrect
    // Or deer -> deers.
    return string;
}

void fact(char *string)
{
    // Prints the first character of the string
    printf("%s starts with the letter %c\n", string, string[0]);
}

char *substring(char *string, char *string2)
{
    // Need the length of both to manipulate the for loops
    int master_str_len = strlen(string);
    int inside_str_len = strlen(string2);
    char check_string[SIZE];

    for (int i = 0; i < master_str_len; ++i)
    {
        // If the character at index i == the first
        // character of string2, it could be the beginning
        // of the found string2
        if (string[i] == string2[0])
        {
            // Copies a substring of strlen(string2) from
            // string1 into check_string
            for (int j = 0; j < inside_str_len; ++j)
            {
                check_string[j] = string[j + i];
                check_string[j + 1] = '\0';
            }
        }

        // Compares the two
        int result = strcmp(string2, check_string);

        if (result == 0)
            // Returns address of character at string[i]
            return &string[i];
    }

    // If it isn't found, return a NULL pointer
    return NULL;
}



