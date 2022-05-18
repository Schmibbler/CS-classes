#include <stdio.h>
#include <string.h>
#include <ctype.h>

void wonky(char *input, int string_length);

int main (void)
{

    char input[100];
    char output[100];
    printf("Enter a sentence: \n");
    fgets(input, 100, stdin);

    wonky(input, strlen(input));

    strcpy(output, input);

    printf("The modified statement is: %s\n", output);





    return 0;
}

void wonky(char *input, int string_length)
{
    for (int i = 0; i < string_length; ++i)
        if (i % 2 == 0)
            input[i] = (char)tolower((int)input[i]);
        else if (i % 2 == 1)
            input[i] = (char)toupper((int)input[i]);
}



