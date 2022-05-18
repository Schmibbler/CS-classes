#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * leftchild;
    struct node_s * rightchild;
} node_t;

node_t * createNode(int data);
node_t * insert(node_t * root, int data);
node_t * search(node_t * root, int data);
node_t * removeNode(node_t * root, int data);
void inorder(node_t * root);
void preorder(node_t * root);
void postorder(node_t * root);
int height(node_t * root);
void printLevel(node_t * root, int level);
int is_bst(node_t * root);

int main (void)
{
    node_t * root = NULL;

    for (int i = 0; i < 10; i++)
        root = insert(root, rand() % 1000);

    printf("Displaying inorder!\n");
    inorder(root);



    int height_num = height(root);
    printf("Height of tree is %d nodes!\n", height_num);



    //root->rightchild->rightchild = createNode(0);
    printf("Printing visualization!\n");
    for (int i = 1; i <= height_num; i++)
    {
        printLevel(root, i);
        printf("\n");
    }
    if (is_bst(root) == 1)
        printf("It's a bst!\n");
    else
        printf("This is not a BST!\n");



    return 0;
}

int is_bst(node_t * root)
{
    if (root == NULL)
        return 1;

    if (root->leftchild != NULL && root->leftchild->data > root->data)
        return 0;

    if (root->rightchild != NULL && root->rightchild->data > root->data)
        return 0;
    if (!is_bst(root->leftchild) || is_bst(root->rightchild))
        return 0;

    return 1;
}

void printLevel(node_t * root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printLevel(root->leftchild, level - 1);
        printLevel(root->rightchild, level - 1);
    }
}

int height(node_t * root)
{
    if (root == NULL)
        return 0;

    int left_height = height(root->leftchild);
    int right_height = height(root->rightchild);

    if (left_height > right_height)
        return (1 + left_height);
    else
        return (1 + right_height);

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

void inorder(node_t * root)
{
    if (root != NULL)
    {
        inorder(root->leftchild);
        inorder(root->rightchild);
        printf("%d\n",root->data);
    }
}

node_t * removeNode(node_t * root, int data)
{
    if(root ==  NULL)
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

node_t * search(node_t * root, int data)
{
    if(root == NULL)
        return NULL;
    if (data < root->data)
        root = search(root->leftchild, data);
    else if (data > root->data)
        root = search(root->rightchild, data);
    else if (data == root->data)
        return root;
    else
        return NULL;
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

node_t * createNode(int data)
{
    node_t * new_node = (node_t * ) malloc(sizeof(node_t) * 1);

    if (new_node == NULL)
    {
        printf("Bad malloc!\n");
        exit(69);
    }

    new_node->leftchild = NULL;
    new_node->rightchild = NULL;
    new_node->data = data;
    return new_node;


}
