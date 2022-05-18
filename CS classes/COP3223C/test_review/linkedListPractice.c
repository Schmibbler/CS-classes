#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int data;
    struct node_s *nextnode;
} node_t;

int empty(node_t *head);
node_t * createNode();
void display(node_t *head);
node_t * insert_back(node_t *node);

int main (void)
{
    node_t *head = NULL;
    for (int i = 0; i < 5; i++)
        head = insert_back(head);
    display(head);

}

int empty(node_t *head)
{

    if (head == NULL)
        return 1;
    else
        return 0;
}

node_t * insert_back(node_t *node)
{
    if (empty(node))
    {
        printf("Inserting new head...\n");
        node_t *head = createNode();
        return head;
    }

    node_t *head = node;
    while (node->nextnode != NULL)
        node = node->nextnode;
    node->nextnode = createNode();
    return head;
}

node_t * createNode()
{
    node_t *node = (node_t *) malloc (sizeof(node_t) * 1);
    if (node == NULL)
    {
        printf("Unsuccessful malloc call...\n");
        return NULL;
    }
    node->data = rand() % 100;
    node->nextnode = NULL;
    return node;
}

void display(node_t *head)
{

    node_t *node = head;
    while (node != NULL)
    {
        printf("-----\n");
        printf("Node address: %p\n", node);
        printf("Node data: %d\n", node->data);
        printf("-----\n");
        node = node->nextnode;
    }
}

