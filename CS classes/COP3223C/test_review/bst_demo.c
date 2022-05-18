#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
     struct node_s * leftchild;
     struct ndoe_s * rightchild;
}node_t;

node_t * createNode(int val);
node_t * insertR(node_t *root, int val);

node_t * removeNode(node_t * root, int val);
int main (void)
{
    node_t * root = NULL;
    root = insertR(root, 10);
    root = insertR(root, 2);
    root = insertR(root, 5);
    root = insertR(root, 7);
    return 0;
}

node_t * createNode(int val)
{
    node_t * node = (node_t *) malloc(sizeof(node_t));

    if(node == NULL)
    {
        printf("malloc bad\n");
        return NULL;
    }

    node->data = val;
    node->leftchild = NULL;
    node->rightchild = NULL;
    return node;

}

node_t * insertR(node_t *root, int val)
{
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->leftchild = insertR(root->leftchild, val);
    else
        root->rightchild = insertR(root->leftchild, val);

    return root;
}

node_t * removeNode(node_t * root, int val)
{
    if(root == NULL)
    {
        printf("Node does not exist");
        return root;
    }
    else if (val < root->data)
    {
        root->leftchild = removeNode(root->leftchild, val);
    }
    else if (val > root->data)
    {
        root->rightchild = removeNode(root->rightchild, val);
    }

}
