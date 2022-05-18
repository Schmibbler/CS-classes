#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int height;
    int data;
    struct node_s * leftchild;
    struct node_s * rightchild;
} node_t;

// Display functions for any tree
void preorder(node_t * root);
void inorder(node_t * root);
void postorder(node_t * root);

// Allocate memory for the function
node_t * createNode(int data);

// Insert and remove
node_t * insert(node_t * root, int data);
node_t * removeNode(node_t * root, int data);

int main (void)
{
    node_t * root = NULL;
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 19);

    root = removeNode(root, 19);
    root = removeNode(root, 2);


    inorder(root);

    return 0;
}


node_t * removeNode(node_t * root, int data)
{
    if (data < root->data)
        root->leftchild = removeNode(root->leftchild, data);
    else if (data > root->data)
        root->rightchild = removeNode(root->rightchild, data);
    else
    {
        if (root->leftchild == NULL)
        {
            node_t * temp = root->rightchild;
            free(root);
            return temp;
        }

        else if (root->leftchild != NULL)
        {
            node_t * temp = root->leftchild;
            free(root);
            return temp;
        }

        else
        {
            node_t * temp = root->rightchild;
            while (temp->leftchild != NULL)
                temp = temp->leftchild;
            root->data = temp->data;
            root->rightchild = removeNode(root->rightchild, temp->data);

        }

    }
}

node_t * insert(node_t * root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (root->data < data)
        root->rightchild = insert(root->rightchild, data);
    else if (root->data > data)
        root->leftchild = insert(root->leftchild, data);
    return root;
}

node_t * createNode(int data)
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);
    new_node->data = data;
    new_node->leftchild = NULL;
    new_node->rightchild = NULL;
    return new_node;
}

void postorder(node_t * root)
{
    if (root != NULL)
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        printf("%d ", root->data);
    }
}

void preorder(node_t * root)
{
    if (root != NULL)
    {
        printf("%d \n", root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}

void inorder(node_t * root)
{
    if (root != NULL)
    {
        inorder(root->leftchild);
        printf("%d \n", root->data);
        inorder(root->rightchild);
    }
}
