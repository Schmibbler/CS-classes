#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trienode_s{
    struct trienode_s * children[26];
    int flag;
} trienode_t;

trienode_t * getTrieNode();
void insert(trienode_t * root, char * string);

int main (void)
{

    trienode_t * root = getTrieNode();
    insert(root, "pea");
    insert(root, "peach");
    insert(root, "peaches");
    insert(root, "peelmp");
    insert(root, "leemlop");
    insert(root, "peachilmpy");


    return 0;
}


void insert(trienode_t * root, char * string)
{
    int length = strlen(string);

    trienode_t * temp = root;
    for (int level = 0; level < length; level++)
    {
        int index = string[level] - 'a';
        if (temp->children[index] == NULL)
            temp->children[index] = getTrieNode();
        temp = temp->children[index];
    }

    temp->flag = 1;

}

trienode_t * getTrieNode()
{
    trienode_t * new_node = (trienode_t *) malloc(sizeof(trienode_t) * 1);
    if (new_node != NULL)
    {
        new_node->flag = 0;
        for (int i = 0; i < 26; i++)
            new_node->children[i] = NULL;
        return new_node;
    }
    return NULL;
}
