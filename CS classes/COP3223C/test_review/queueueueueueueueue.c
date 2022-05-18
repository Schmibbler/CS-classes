#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * nextptr;
} node_t;

node_t * createNode();
node_t * enqueue(node_t * front);
int isEmpty(node_t * front);
void display(node_t * front);
node_t * dequeue(node_t * front);

int main (void)
{

    node_t * front = NULL;
    printf("Adding 5 nodes to the queue!\n");
    for (int i = 0; i < 5; i++)
        front = enqueue(front);
    display(front);

    printf("Dequeuing 3 nodes!\n");
    for (int i = 0; i < 3; i++)
        front = dequeue(front);
    display(front);



    return 0;
}

node_t * dequeue(node_t * front)
{
    if (isEmpty(front))
    {
        printf("Nothing to remove!\n");
        return NULL;
    }

    if(front->nextptr == front)
    {
        printf("Only one item to remove!\n");
        free(front);
        return NULL;
    }

    node_t * temp = front;
    node_t * temp2 = front->nextptr;
    front = front->nextptr;
    while (temp2->nextptr != temp)
        temp2 = temp2->nextptr;
    temp2->nextptr = front;
    free(temp);

    return front;
}

void display(node_t * front)
{
    printf("Displaying queue....\n");
    node_t * temp = front->nextptr;
    printf(" ---\n");
    printf("| %d |\n", front->data);
    printf(" ---\n");
    while (temp != front)
    {
        printf(" ---\n");
        printf("| %d |\n", temp->data);
        printf(" ---\n");
        temp = temp->nextptr;
    }
}

int isEmpty(node_t * front)
{
    return (front == NULL);
}
node_t * enqueue(node_t * front)
{
    if(isEmpty(front))
    {
        printf("No items in queue! Adding...\n");
        front = createNode();
        front->nextptr = front;
        return front;
    }
    if (front->nextptr == front)
    {
        printf("One item in queue!\n");
        node_t * new_node = createNode();
        front->nextptr = new_node;
        front->nextptr->nextptr = front;
        return front;
    }

    node_t * temp = front->nextptr;
    while (temp->nextptr != front)
        temp = temp->nextptr;
    temp->nextptr = createNode();
    temp->nextptr->nextptr = front;
    return front;
}

node_t * createNode()
{
    node_t * new_node = (node_t *)malloc(sizeof(node_t) * 1);
    if (new_node == NULL)
    {
        printf("Wee woo queueueueueueueeuueueueueuue misallocation!\n");
        exit(69420);
    }
    new_node->nextptr = NULL;
    new_node->data = rand() % 100;
    return new_node;
}
