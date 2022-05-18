#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **insert(char **rows, int *word_qty, int *max_words);
void display(char **rows, int *word_qty);
void del_word(char **rows, int *word_qty);
char **reverse(char **rows, int *word_qty);
int main (void)
{
    char* mode = "r";
    FILE *fp;
    fp = fopen("words.txt", mode);

    int max_words = 20;
    int word_qty = 10;

    char **rows = (char **) malloc(word_qty * sizeof(char*));

    for (int i = 0; i < word_qty; i++)
    {
        char temp_string[50];
        fscanf(fp, "%s", temp_string);
        int char_count = strlen(temp_string);
        char string[char_count];
        strcpy(string, temp_string);
        rows[i] = (char *) malloc(char_count * sizeof(char));
        strcpy(rows[i], string);
    }

    printf("Initial words: \n");
    display(rows, &word_qty);


    int option = -1;
    do
    {
        printf("Make a menu selection:\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Reverse, Reverse!\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("Displaying...\n");
                display(rows, &word_qty);
                break;
            case 2:
                printf("Insert selected...\n");
                insert(rows, &word_qty, &max_words);
                break;
            case 3:
                printf("Delete selected...\n");
                del_word(rows, &word_qty);
                break;
            case 4:
                printf("Reversing the array...\n");
                rows = reverse(rows, &word_qty);
                break;
            case 5:
                printf("Exiting...\n");
                option = 5;
                break;
            default:
                printf("Invalid selection");
                break;
        }

    } while (option != 5);

    // Write above here
    for (int i = 0; i < word_qty; i++)
    {
        free(rows[i]);
        rows[i] = NULL;
    }

    free(rows);
    rows = NULL;


    return 0;
}

void del_word(char **rows, int *word_qty)
{
    char del_string[100];
    printf("Enter the word you wish to delete: \n");
    scanf("%s", del_string);
    char string[strlen(del_string)];
    strcpy(string, del_string);
    int found = 0;
    for (int i = 0; i < *word_qty; i++)
    {
        if (strcmp(rows[i], string) == 0)
        {
            found++;
            for (int j = i; j < *word_qty; j++)
                rows[j] = rows[j + 1];
            *word_qty -= 1;
        }
    }
    if (found == 0)
        printf("String not found!\n");
}


char **insert(char **rows, int *word_qty, int *max_words)
{
    if ((*word_qty + 1) > *max_words)
    {
        printf("Insufficient memory to handle, returning...\n");
        return rows;
    }

    printf("Inserting word...\n");
    char string[100];
    printf("Type a word to insert:");
    scanf("%s", string);
    rows[*word_qty] = (char *) malloc(strlen(string) * sizeof(char));
    strcpy(rows[*word_qty], string);
    *word_qty += 1;
    return rows;
}

void display(char **rows, int *word_qty)
{
    for (int i = 0; i < *word_qty; i++)
        printf("%s\n", rows[i]);
}

char **reverse(char **rows, int *word_qty)
{
    char **rev_row = (char **) malloc(*word_qty * sizeof(char*));
    for (int i = 0; i < *word_qty; i++)
    {
        rev_row[i] = (char *) malloc(strlen(rows[(*word_qty - 1) - i]) * sizeof(char));
        strcpy(rev_row[i], rows[(*word_qty - 1) - i]);
    }
    return rev_row;
}

