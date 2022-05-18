#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
    char word1[MAX];
    char word2[MAX];
} words_t;


int main (void)
{
    FILE *fp;
    char *m = "r";
    fopen("words.txt", m);
    if (fp == NULL)
    {
        printf("File not found.\n");
        return 0;

    }

    words_t words[5];

    printf("Initializing structures...\n");

    for (int i = 0; i < 5; i++)
    {
        char string[MAX];
        char string2[MAX];
        printf("Made it to line 32...\n");
        fscanf(fp, "%s", string);
        printf("Made it to line 34...\n");
        strcpy(words->word1, string);

        fscanf(fp, "%s", string2);
        strcpy(words->word2, string2);

    }

    printf("Printing structures...\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Struct %d:\n", i);
        printf("%s\n", words->word1);
        printf("%s\n", words->word2);
    }
    fclose(fp);
    return 0;
}
