/*
•Insert
•Remove
•Display (traverse)
•Search
•Empty
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * nextptr;
} node_t;

int empty(node_t * head);
node_t * createNode();
node_t * insert_node(node_t * head);
void display_nodes(node_t * head);
node_t * search(node_t * head, int data);
node_t * remove_node(node_t * head, node_t * node);

int main (void)
{
    node_t * head = NULL;
    if (empty(head))
        printf("Empty!\n");
    else
        printf("Not empty!\n");

    for (int i = 0; i < 100; i++)
        head = insert_node(head);

    display_nodes(head);

    int find_data = 50;

    printf("Searching for a node with value %d!\n", find_data);
    node_t * found_node = search(head, 50);
    if (found_node != NULL)
        printf("Found the node! Address of %p\n", found_node);
    else
        printf("No nodes exist with the value of %d!", find_data);

    printf("Removing node with value %d\n", find_data);

    head = remove_node(head, found_node);

    printf("Removed that node!\n");

    printf("Now attempting to remove allllllll values of nodes less than 50!\n");

    node_t * current_node = head;
    while (current_node->nextptr != NULL)
    {
        if (current_node->nextptr->data > 10)
        {
            node_t * temp = current_node->nextptr;
            current_node->nextptr = current_node->nextptr->nextptr;
    printf("|||||Current_node is now %p, %d\n", current_node, current_node->data);
                current_node = current_node->nextptr->nextptr;
            printf("Current_node is now %p, %d\n", current_node, current_node->data);
            free(temp);


            continue;
        }

        current_node = current_node->nextptr;
    }
    printf("The new linked list is this!\n");

    display_nodes(head);





    return 0;
}

node_t * remove_node(node_t * head, node_t * node)
{
    if (head->nextptr == NULL)
    {
        free(head);
        return NULL;
    }
    node_t * current_node = head;
    while (current_node->nextptr != NULL)
    {
        if (current_node->nextptr == node)
        {
            node_t * temp = current_node->nextptr;
            current_node->nextptr = current_node->nextptr->nextptr;
            free(temp);
            return head;
        }
        current_node = current_node->nextptr;
    }

    return NULL;


}

int empty(node_t * head)
{
    return (head == NULL);
}

node_t * createNode()
{

    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);
    if (new_node == NULL)
    {
        printf("Malloc not good\n");
        exit(1);
    }
    new_node->data = rand() % 100;

    return new_node;
}

node_t * insert_node(node_t * head)
{
    if (empty(head))
    {
        printf("This is empty! Creating new head!\n");
        node_t * node = createNode();
        node->data = rand() % 10;
        node->nextptr = NULL;
        return node;
    }

    node_t * current_node = head;
    while (current_node->nextptr != NULL)
        current_node = current_node->nextptr;
    current_node->nextptr = createNode();
    current_node->nextptr->nextptr = NULL;

    return head;
}

node_t * search(node_t * head, int data)
{
    node_t * current_node = head;
    while (current_node != NULL)
    {
        if (current_node->data == data)
            return current_node;
        current_node = current_node->nextptr;
    }
    return NULL;


}


void display_nodes(node_t * head)
{
    node_t * current_node = head;
    while (current_node != NULL)
    {
        printf("------\n");
        printf("|  %d  |\n", current_node->data);
        printf("------\n");
        current_node = current_node->nextptr;

    }

}
