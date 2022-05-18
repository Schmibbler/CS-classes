#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node_s {
    char * word;
    struct node_s * left;
    struct node_s * right;
} node_t;

node_t * insert(node_t * root, char * word);
node_t * createNode(char * word);
void inorder(node_t * root);

int main (void)
{
    FILE * fp = fopen("words.txt", "r");
    node_t * root = NULL;
    char * word;

    for (int i = 0; i < 48; i++)
    {
        word = (char *) malloc(sizeof(char) * 15);
        if (word == NULL)
            exit(1);
        fscanf(fp, "%s", word);
        root = insert(root, word);
    }
    inorder(root);
}

void inorder(node_t * root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s\n", root->word);
        inorder(root->right);
    }

}

node_t * insert(node_t * root, char * word)
{
    if (root == NULL)
        return createNode(word);
    int result = strcmp(word, root->word);
    if (result < 0)
        root->left = insert(root->left, word);
    else if (result > 0)
        root->right = insert(root->right, word);
    else
        return root;
}

node_t * createNode(char * word)
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);
    new_node->word = word;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


