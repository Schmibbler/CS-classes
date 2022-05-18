/*
    insert
    delete
    traversal
        inorder
        preorder
        postorder
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    double data;
    struct node_s * leftchild;
    struct node_s * rightchild;
} node_t;

node_t * createNode(double data);
int is_full_bst(node_t * root);

node_t * insert(node_t * root, double data);

void inorder(node_t * root);
void preorder(node_t * root);
void postorder(node_t * root);


void leaf_count(node_t * root, int * current_count);
int is_complete_bst(node_t * root);
void count_nodes(node_t * root, int * count);
int maxDepth(node_t * node);

int main (void)
{
    node_t * root = NULL;
    for (int i = 0; i < 20; i++)
        root = insert(root, (rand() % 1000) + (rand() % 100) / 100.0);


    printf("Displaying tree inorder!\n");
    inorder(root);
    printf("Displaying tree preorder!\n");
    preorder(root);
    printf("Displaying tree postorder!\n");
    postorder(root);


    int leaves = 0;
    leaf_count(root, &leaves);

    printf("There are %d leaves in this tree!\n", leaves);

    int is_full = 1;
    is_full = is_full_bst(root);
    if (is_full)
        printf("Every node in this tree has either 2 or 0 child nodes!\n");
    else
        printf("This tree is not full!\n");

    int node_count = 0;
    count_nodes(root, &node_count);
    printf("There are %d nodes in this tree!\n", node_count);
    int depth = maxDepth(root);
    printf("The height of the tree is %d units!\n", depth);
    printf("At this height of %d units, there can be a theoretical maximum of %d nodes!\n", depth, (1<<depth));

}


void postorder(node_t * root)
{
    if (root != NULL)
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        printf("%.2lf\n", root->data);
    }
}

void preorder(node_t * root)
{
    if (root != NULL)
    {
        printf("%.2lf\n", root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);

    }
}

int maxDepth(node_t * node)
{
    if (node == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->leftchild);
        int rDepth = maxDepth(node->rightchild);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void count_nodes(node_t * root, int * count)
{
    if (root != NULL)
    {
        count_nodes(root->leftchild, count);
        (*count)++;
        count_nodes(root->rightchild, count);
    }
}

int is_complete_bst(node_t * root)
{
    if (root != NULL)
    {
        is_complete_bst(root->leftchild);

        is_complete_bst(root->rightchild);
    }
}

int is_full_bst(node_t * root)
{
    if (root != NULL)
    {
        is_full_bst(root->leftchild);
        if ((root->leftchild != NULL && root->rightchild == NULL) || (root->rightchild != NULL && root->leftchild == NULL))
            return 0;
        is_full_bst(root->rightchild);
    }
}

void leaf_count(node_t * root, int * current_count)
{
    if (root != NULL)
    {
        leaf_count(root->leftchild, current_count);
        if (root->leftchild == NULL && root->rightchild == NULL)
            (*current_count)++;
        leaf_count(root->rightchild, current_count);
    }

}

void inorder(node_t * root)
{
    if (root != NULL)
    {
        inorder(root->leftchild);
        printf("%.2lf\n", root->data);
        inorder(root->rightchild);
    }
}

node_t * insert(node_t * root, double data)
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

node_t * createNode(double data)
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t ) * 1);
    if (new_node == NULL)
    {
        printf("Malloc didn't work!\n");
        exit(1);
    }

    new_node->data = data;
    new_node->leftchild = NULL;
    new_node->rightchild = NULL;
    return new_node;
}
