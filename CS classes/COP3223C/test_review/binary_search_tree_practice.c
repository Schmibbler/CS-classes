/*
insert
delete
search
traversal
    -inorder
    -preorder
    -postorder
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * leftchild;
    struct node_s * rightchild;
} node_t;

node_t * search(node_t * root, int data);
node_t * insert(node_t * root, int data);
node_t * createNode(int data);
node_t * removeNode(node_t * root, int data);
void inorder(node_t * root);
void preorder(node_t * root);
void postorder(node_t * root);



int main (void)
{

    node_t * root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 13);
    root = insert(root, 12);
    root = insert(root, 15);
    root = insert(root, 14);

    printf("inorder:\n");
    inorder(root);
    printf("preorder:\n");
    preorder(root);
    printf("postorder:\n");
    postorder(root);

    root = removeNode(root, 6);
    root = removeNode(root, root->data);


    return 0;
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
        printf("%d\n", root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
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

node_t * insert(node_t * root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->leftchild = insert(root->leftchild, data);
    else if (data > root->data)
        root->rightchild = insert(root->rightchild, data);
    else
        return root;

}

node_t * removeNode(node_t * root, int data)
{
    if (root == NULL)
    {
        printf("Empty node found!\n");
        return NULL;
    }
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
        } else if (root->leftchild == NULL)
        {
            node_t * temp = root->leftchild;
            free(root);
            return temp;
        }
        node_t * temp = root->rightchild;
        root->data = temp->data;
        while (temp->leftchild != NULL)
            temp = temp->leftchild;

        root->rightchild = removeNode(root->rightchild, temp->data);

    }
    return root;


}

node_t * createNode(int data)
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);
    if (new_node == NULL)
    {
        printf("Bad malloc!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->leftchild = NULL;
    new_node->rightchild = NULL;
    return new_node;
}

node_t * search(node_t * root, int data)
{
    if (root == NULL)
    {
        printf("No items in tree!\n");
        return NULL;
    }
    while (root != NULL)
    {
        if (data > root->data)
            root = root->rightchild;
        else if (data < root->data)
            root = root->leftchild;
        else
            return root;
    }
    return NULL;
}
