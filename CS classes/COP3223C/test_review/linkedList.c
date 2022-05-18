#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {

    int data;
    struct node_s * nextptr;

} node_t;

node_t * push(node_t *top, int val);
int is_empty(node_t *top);
node_t * createNode(int data);

int main (void)
{
    node_t * top = NULL;
    if (is_empty(top))
        printf("Empty Stack!\n");
    top = push(top, rand()%100);

    return 0;
}

int is_empty(node_t *top)
{
    return (top == NULL);
}

node_t * push(node_t *top, int val)
{
    if (is_empty(top))
    {
        printf("Stack is empty... creating top value");
        top->data = val;
        top->nextptr = NULL;
        return top;
    }

    node_t * new_node = createNode(val);
    if (new_node != NULL)
    {
        new_node->nextptr = top;
        return new_node;
    }
    else
        return NULL;

}

node_t * createNode(int data)
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t *) * 1);
    if (new_node == NULL)
    {
        printf("Malloc unsuccessful...\n");
        return NULL;
    }
    new_node->data = data;
    new_node->nextptr = NULL;
    return new_node;
}

