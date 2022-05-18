#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trienode_s{
    struct trienode_s * children[26];
    int flag;
}trienode_t;

// Insert
// Delete
// Search

trienode_t * create_node();
void insert(trienode_t * root, char * string);
int words_in_trie(trienode_t * root);
void display(trienode_t * root, char * string, int level);
int count_words(trienode_t * root, int * count);
int longest_word_length(trienode_t * root, int level);
void clear(char ** mega_string, int length);

// Alpha
void alphabetize(trienode_t * root, char ** dyn_string, char * current_string, int level, int * word_index);

int main (void)
{

    trienode_t * root = create_node();

    char word[20];
    insert(root, "zanzibar");
    insert(root, "zoo");
    insert(root, "zealot");
    insert(root, "zealous");
    insert(root, "aardvark");
    insert(root, "argon");
    insert(root, "argentavis");
    insert(root, "arnie");
    insert(root, "apples");
    insert(root, "application");
    insert(root, "applications");
    insert(root, "app");
    insert(root, "append");
    insert(root, "apprehension");
    insert(root, "zzzzzzzzzz");
    insert(root, "zzzzzzzzz");

    int count = 0;
    count_words(root, &count);
    printf("There are %d words in the trie\n", count);


    int longest_word_len = longest_word_length(root, 0);
    printf("The longest word is %d characters long\n", longest_word_len);

    int word_index = 0;

    char ** dyn_string = (char **) malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count; ++i)
        dyn_string[i] = (char *) malloc(sizeof(char) * (longest_word_len + 1));


    alphabetize(root, dyn_string, word, 0, &word_index);
    printf("Here is the alphabetized version of the trie!\n");
    for (int i = 0; i < count; ++i)
        printf("%s\n", dyn_string[i]);

    clear(dyn_string, count);
    return 0;

}

void clear(char ** mega_string, int length)
{
    for (int i = 0; i < length; ++i)
        free(mega_string[i]);
    free(mega_string);
}

void alphabetize(trienode_t * root, char ** dyn_string, char * current_string, int level, int * word_index)
{
    if (root->flag == 1)
    {
        current_string[level] = '\0';
        strcpy(dyn_string[(*word_index)], current_string);
        (*word_index) += 1;
    }
    for (int i = 0; i < 26; ++i)
        if (root->children[i])
        {
            current_string[level] = i + 'a';
            alphabetize(root->children[i], dyn_string, current_string, level + 1, word_index);
        }
}


int longest_word_length(trienode_t * root, int level)
{
    int curr_level;
    int longest = level;
    for (int i = 0; i < 26; ++i)
        if (root->children[i])
        {
            curr_level = longest_word_length(root->children[i], level + 1);
            if (curr_level > longest)
                longest = curr_level;
        }
    return longest;
}

trienode_t * create_node()
{
    trienode_t * new_node = (trienode_t *) malloc(sizeof(trienode_t) * 1);
    new_node->flag = 0;
    for (int i = 0; i < 26; i++)
        new_node->children[i] = NULL;
    return new_node;
}

void insert(trienode_t * root, char * string)
{
    int length = strlen(string);

    trienode_t * temp = root;
    for (int level = 0; level < length; level++)
    {
        int index = string[level] - 'a';
        if (temp->children[index] == NULL)
            temp->children[index] = create_node();
        temp = temp->children[index];
    }

    temp->flag = 1;

}

int search(trienode_t * root, char * string)
{
    int length = strlen(string);
    trienode_t * temp = root;
    int index;
    for (int i = 0; i < length; ++i)
    {
        index = string[i] - 'a';
        if (temp->children[index] == NULL)
            return 0;
        temp = temp->children[index];
    }
    return temp->flag;
}

int count_words(trienode_t * root, int * count)
{
    if (root->flag == 1)
        (*count) += 1;

    for (int i = 0; i < 26; ++i)
        if (root->children[i])
            count_words(root->children[i], count);
}


void display(trienode_t * root, char * string, int level)
{
    if (root->flag == 1)
    {
        string[level] = '\0';
        printf("%s\n", string);
    }

    for (int i = 0; i < 26; ++i)
    {
        if (root->children[i])
        {
            string[level] = i + 'a';
            display(root->children[i], string, level + 1);
        }
    }
}






