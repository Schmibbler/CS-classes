#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15


typedef struct trienode_s {
    int flag;
    struct trienode_s * children[26];
} trienode_t;

void display(trienode_t * root, char * curr_string, int level);
void insert(trienode_t * root, char * string);
trienode_t * create_node();
int longest_word(trienode_t * root, int level);
int count_words(trienode_t * root);
void alphabetize(trienode_t * root, char ** full_structure, int level, char * curr_string, int * curr_index);
void first_in_trie(trienode_t * root, char * curr_string, int level);

int main (void)
{
    trienode_t * root = create_node();
    char str[MAX];
    strcpy(str, "hello");


    insert(root, "hello");
    insert(root, "help");
    insert(root, "hellish");
    insert(root, "heel");
    insert(root, "glormp");
    insert(root, "glompy");
    insert(root, "glombo");
    insert(root, "zzoo");
    insert(root, "aaaaaaaaaaa");


    char word[MAX];
    //display(root, word, 0);

    int count = 0;
    count = count_words(root);
    printf("There are %d words in the trie!\n", count);

    int max = longest_word(root, 0);
    printf("The longest word is %d letters long!\n", max);
    char ** trie_structure = (char **) malloc(sizeof(char *) * count);
    for (int i = 0; i < count; i++)
        trie_structure[i] = (char *) malloc(sizeof(char) * (max + 1));

    int curr_count = 0;
    alphabetize(root, trie_structure, 0, word, &curr_count);
    curr_count = 0;
    char first_word[MAX];
    first_in_trie(root, first_word, 0);
    printf("The first word SHOULD be %s\n", first_word);
    return 0;
}

void first_in_trie(trienode_t * root, char * curr_string, int level)
{
    if (root->flag == 1) {
        curr_string[level] = '\0';
        return curr_string;
    }
    for (int i = 0; i < 26; i++)
        if (root->children[i]) {
            curr_string[level] = i + 'a';
            return first_in_trie(root->children[i], curr_string, level + 1);
        }
}

void alphabetize(trienode_t * root, char ** full_structure, int level, char * curr_string, int * curr_index)
{
    if (root->flag == 1)
    {
        curr_string[level] = '\0';
        strcpy(full_structure[(*curr_index)], curr_string);
        (*curr_index)++;
    }
    for (int i = 0; i < 26; i++)
        if (root->children[i]) {
            curr_string[level] = i + 'a';
            alphabetize(root->children[i], full_structure, level + 1, curr_string, curr_index);
        }
}

int count_words(trienode_t * root)
{
    int count = 0;
    if (root->flag == 1)
        count++;
    for (int i = 0; i < 26; i++)
        if (root->children[i] != NULL)
            count += count_words(root->children[i]);
    return count;
}

int longest_word(trienode_t * root, int level)
{
    int prev_longest = level;
    int longest = prev_longest;
    for (int i = 0; i < 26; i++)
        if (root->children[i]) {
            prev_longest = longest_word(root->children[i], level + 1);
            if (prev_longest > longest)
                longest = prev_longest;
        }
    return longest;
}

void insert(trienode_t * root, char * string)
{
    int length = strlen(string);
    trienode_t * temp = root;
    for (int level = 0; level < length; ++level)
    {
        int index = string[level] - 'a';
        if (temp->children[index] == NULL)
            temp->children[index] = create_node();
        temp = temp->children[index];
    }
    temp->flag = 1;
}

void display(trienode_t * root, char * curr_string, int level)
{
    if (root->flag == 1)
    {
        curr_string[level] = '\0';
        printf("%s\n", curr_string);
    }
    for (int i = 0; i < 26; ++i)
    {
        if (root->children[i] != NULL)
        {
            curr_string[level] = i + 'a';
            display(root->children[i], curr_string, level + 1);
        }
    }

}

trienode_t * create_node()
{
    trienode_t * node = (trienode_t *) malloc(sizeof(trienode_t) * 1);
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}
