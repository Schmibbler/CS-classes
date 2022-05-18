/*
    BST:
    Insert
    Delete
    Search
    Traversal
        -Inorder
        -Preorder
        -Postorder
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct node_s {
    int data;
    struct node_s * leftchild;
    struct node_s * rightchild;
} node_t;

node_t * insert(node_t * root, int data);
node_t * createNode(int data);

void preorder(node_t * root);
void inorder(node_t * root);
void postorder(node_t * root);
node_t * search(node_t * root, int data);
node_t * removeNode(node_t * root, int data);

node_t * sort_with_bst(node_t * root, int arr[], int * index);



int main (void)
{

    node_t * root = NULL;
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 1000;
        root = insert(root, arr[i]);
    }

    for (int i = 0; i < 10; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    printf("Printing tree!\n");
    inorder(root);

    int index = 0;
    sort_with_bst(root, arr, &index);

    printf("Printing sorted array?\n");
    for (int i = 0; i < 10; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    return 0;
}

node_t * sort_with_bst(node_t * root, int arr[], int * index)
{
    if (root != NULL)
    {
        sort_with_bst(root->leftchild, arr, index);
        arr[(*index)++] = root->data;
        sort_with_bst(root->rightchild, arr, index);
    }
    return NULL;


}

node_t * search(node_t * root, int data)
{
    while (root != NULL)
    {
        if (data > root->data)
            root = root->rightchild;
        else if (data < root->data)
            root = root->leftchild;
        else
            return root;
    }

    printf("Not found!\n");

    return root;


}

void postorder(node_t * root)
{
    if (root != NULL)
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        printf("%d\n", root->data);
    }
}

void preorder(node_t * root)
{
    if (root != NULL)
    {
        printf("%d\n",root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }


}

node_t * removeNode(node_t * root, int data)
{
    if (root == NULL)
        return NULL;

    if (data > root->data)
        root->rightchild = removeNode(root->rightchild, data);
    else if (data < root->data)
        root->leftchild = removeNode(root->leftchild, data);
    else
    {
        if (root->leftchild == NULL)
        {
            node_t * temp = root->rightchild;
            free(root);
            return temp;
        }
        else if (root->rightchild == NULL)
        {
            node_t * temp = root->leftchild;
            free(root);
            return temp;
        }

        node_t * temp = root->rightchild;

        while (temp->leftchild != NULL)
            temp = temp->leftchild;

        root->data = temp->data;

        root->rightchild = removeNode(root->rightchild, temp->data);
    }

    return root;


}

void inorder(node_t * root)
{
    if (root != NULL)
    {
        inorder(root->leftchild);
        printf("%d\n", root->data);
        inorder(root->rightchild);
    }
}

node_t * createNode(int data)
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);
    if (new_node == NULL)
    {
        printf("Incorrect malloc call\n");
        exit(1);
    }
    new_node->data = data;
    new_node->leftchild = NULL;
    new_node->rightchild = NULL;
    return new_node;
}



node_t * insert(node_t * root, int data)
{

    if (root == NULL)
        return createNode(data);
    if (data > root->data)
        root->rightchild = insert(root->rightchild, data);
    else if (data < root->data)
        root->leftchild = insert(root->leftchild, data);
    else
        return root;

}
