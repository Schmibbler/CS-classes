#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct trienode_s {
    int flag;
    struct trienode_s * children[26];
} trienode_t;

void insert(trienode_t * root, char * string);
void display(trienode_t * root, char * curr_string, int level);
trienode_t * create_node();
int main (void)
{

    trienode_t * root = create_node();
    insert(root, "apples");
    insert(root, "butter");
    insert(root, "application");
    insert(root, "apply");
    insert(root, "glommo");
    insert(root, "glomp");
    insert(root, "butt");
    insert(root, "buttress");
    char word[20];
    display(root, word, 0);


    return 0;
}

void insert(trienode_t * root, char * string) {

    int length = strlen(string);
    trienode_t * temp = root;

    for (int i = 0; i < length; i++) {
        int index = string[i] - 'a';
        if (temp->children[index] == NULL)
            temp->children[index] = create_node();
        temp = temp->children[index];
    }
    temp->flag = 1;
}

trienode_t * create_node()
{
    trienode_t * node = (trienode_t *) malloc(sizeof(trienode_t) * 1);
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

void display(trienode_t * root, char * curr_string, int level)
{
    if (root->flag == 1) {
        curr_string[level] = '\0';
        printf("%s\n", curr_string);
    }
    for (int i = 0; i < 26; i++)
        if (root->children[i]) {
            curr_string[level] = i + 'a';
            display(root->children[i], curr_string, level + 1);
        }
}
