/*
Push
Pop
top/peek
is_empty
is_full
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * nextptr;
} node_t;


int is_empty(node_t * top);
node_t * createNode();
node_t * push(node_t * top);
void peek(node_t * top);
void display_stack(node_t * top);
node_t * pop(node_t * top);
int main (void)
{
    node_t * top = NULL;
    printf("Peeking the top!\n");
    for (int i = 0; i < 5; i++)
        top = push(top);

    display_stack(top);
    printf("Popping off the stack!\n");

    for (int i = 0; i < 2; i++)
        top = pop(top);

    printf("New stack is this!\n");
    display_stack(top);




    return 0;
}
node_t * pop(node_t * top)
{
    if (is_empty(top))
    {
        printf("Empty stack!\n");
        return NULL;
    }
    node_t * new_top = top->nextptr;
    free(top);
    return new_top;

}
void display_stack(node_t * top)
{
    node_t * current_node = top;
    while (current_node != NULL)
    {
        printf("-----\n");
        printf("| %d  |\n", current_node->data);
        printf("-----\n");
        current_node = current_node->nextptr;
    }
        printf("-----\n");
        printf("| %p  |\n", current_node);
        printf("-----\n");
}

void peek(node_t * top)
{
    printf("Displaying the top!\n");
    printf("-----\n");
    printf("| %d  |\n", top->data);
    printf("-----\n");

}
node_t * push(node_t * top)
{
    if (is_empty(top))
    {
        printf("The stack is empty!\n");
        printf("Creating fresh node...\n");
        top = createNode();
        top->nextptr = NULL;
        return top;
    } else
    {
        node_t * new_top = createNode();
        new_top->nextptr = top;
        return new_top;
    }
}

int is_empty(node_t * top)
{
    return (top == NULL);
}

node_t * createNode()
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);
    if (new_node == NULL)
    {
        printf("Bad malloc!\n");
        exit(1);
    }
    new_node->data = rand() % 10;
    new_node->nextptr = NULL;
    return new_node;
}
