#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * nextptr;
} node_t;

void top(node_t * top);

int isEmpty(node_t * top);

node_t * createNode();
node_t * pop(node_t * top);
node_t * push(node_t * top);
void display(node_t * top);


int main (void)
{


    node_t * top = NULL;
    printf("Adding to stack!\n");
    for (int i = 0; i < 5; i++)
        top = push(top);
    display(top);

    printf("Popping from stack!\n");
    for (int i = 0; i < 2; i++)
        top = pop(top);
    display(top);



    return 0;
}

node_t * createNode()
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);
    if (new_node == NULL)
    {
        printf("Naughty boy malloc!\n");
        exit(69);
    }

    new_node->nextptr = NULL;
    new_node->data = rand() % 10;
    return new_node;
}

void display(node_t * top)
{
    node_t * temp = top;
    while (temp != NULL)
    {
        printf(" ---\n");
        printf("| %d |\n", temp->data);
        printf(" ---\n");
        temp = temp->nextptr;
    }
}


int isEmpty(node_t * top)
{
    return (top == NULL);
}

node_t * pop(node_t * top)
{
    if (isEmpty(top))
    {
        printf("Nothing to pop!\n");
        return top;
    }

    if (top->nextptr == NULL)
    {
        printf("Last node in stack!\n");
        free(top);
        return NULL;
    }

    node_t * new_top = top->nextptr;
    free(top);
    return new_top;
}

node_t * push(node_t * top)
{
    if(isEmpty(top))
        return createNode();

    node_t * new_node = createNode();
    new_node->nextptr = top;
    return new_node;
}
void top(node_t * top)
{
    if (isEmpty(top))
    {
        printf("No stack to display!\n");
        return;
    }
    printf("Here is the top!\n");
    printf(" ---\n");
    printf("| %d |\n", top->data);
    printf(" ---\n");
}
