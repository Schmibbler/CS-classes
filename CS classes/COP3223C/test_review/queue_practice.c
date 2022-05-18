/*
enqueue
dequeue
front/peek
is_empty
is_full
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * nextptr;
} node_t;

int isEmpty(node_t * front);
node_t * enqueue(node_t * front);
node_t * createNode();
void peek(node_t * front);
void display_queue(node_t * front);
node_t * dequeue(node_t * front);

int main (void)
{
    node_t * front = NULL;
    front = enqueue(front);
    front = enqueue(front);
    front = enqueue(front);
    front = enqueue(front);
    peek(front);

    display_queue(front);


    return 0;
}
void display_queue(node_t * front)
{
    if (isEmpty(front))
    {
        printf("Nothing to display!\n");

    }
    if (front->nextptr = front)
    {
        printf("| %p, %d |\n", front, front->data);

    }

    printf("HERE");
    printf("| %p, %d |\n", front, front->data);
    node_t * current = front;
    while (current->nextptr != front)
    {
        printf("| %p, %d |\n", current, current->data);
        current = current->nextptr;
    }
    return;
}
void peek(node_t * front)
{
    printf("Front of queue is %p, %d\n", front, front->data);
}

node_t * dequeue(node_t * front)
{
    printf("Dequeuing...\n");
    if (isEmpty(front))
    {
        printf("No nodes detected!\n");
        return NULL;
    }
    if (front->nextptr == front)
    {
        free(front);
        return NULL;
    }
    node_t * temp = front;
    front = front->nextptr;
    node_t * temp2 = front;
    while (temp2->nextptr != temp)
        temp2 = temp2->nextptr;
    temp2->nextptr = front;
    free(temp);
    return front;

}

node_t * enqueue(node_t * front)
{
    node_t * new_node;
    if (isEmpty(front))
    {
        printf("Empty queue detected!\n");
        new_node = createNode();
        new_node->nextptr = new_node;
        return new_node;
    }
    if (front->nextptr = front)
    {
        new_node = createNode();
        new_node->nextptr = front;
        front->nextptr = new_node;
        return front;
    }

    node_t * current = front->nextptr;
    while (current->nextptr != front)
        current = current->nextptr;

    new_node = createNode();
    current->nextptr = new_node;
    current->nextptr->nextptr = front;

    return front;

}
node_t * createNode()
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t ) * 1);
    if (new_node == NULL)
    {
        printf("Bad malloc call\n");
        exit(1);
    }
    new_node->data = rand() % 10;
    new_node->nextptr = NULL;
    return new_node;

}



int isEmpty(node_t * front)
{
    return (front == NULL);
}
