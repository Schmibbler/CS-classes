#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * nextptr;
} node_t;

int empty(node_t * front);
node_t * createNode();
node_t * enqueue(node_t * front);
node_t * dequeue(node_t * front);
void display(node_t * front);
void front(node_t * front);

int main (void)
{

    node_t * front = NULL;

    if(empty(front))
        printf("Empty, no one is in line\n");

    front = enqueue(front);
    front = enqueue(front);
    front = enqueue(front);
    front = enqueue(front);
    front = enqueue(front);
    display(front);
    front = dequeue(front);
    display(front);
    front = dequeue(front);
    display(front);
    front = dequeue(front);
    display(front);
    front = dequeue(front);
    display(front);
    front = dequeue(front);
    display(front);
    front = dequeue(front);
    display(front);
    front = dequeue(front);
    display(front);

    return 0;
}

int empty(node_t * front)
{
    return (front == NULL);
}



node_t * createNode()
{
    node_t * node = (node_t *) malloc (sizeof(node_t) * 1);

    node->data = rand() % 10;
    node->nextptr = NULL;
    if (node == NULL)
        exit(1);



    return node;
}

node_t * enqueue(node_t * front)
{
    if (empty(front))
    {
        printf("A new node will become the front...\n");
        front = createNode();
        front->nextptr = front;
        return front;
    }
    node_t * temp = front;

    while(temp->nextptr != front)
        temp = temp->nextptr;

    temp->nextptr = createNode();
    temp->nextptr->nextptr = front;
    return front;
}

void display(node_t * front)
{
    if (!empty(front))
    {
        node_t * first = front;
        while(front->nextptr != first)
        {
            printf("%d\t", front->data);
            front = front->nextptr;
        }
        printf("%d\t", front->data);
        printf("\n");
    }
    else
        printf("null...\n");


}

node_t * dequeue(node_t * front)
{
    if (empty(front))
    {
        printf("Queue is empty and there isn't anything to remove...\n");
        return front;
    }
    else if (front->nextptr == front)
    {
        free(front);
        front = NULL;
        return NULL;
    }
    else
    {
        node_t * temp = front;
        front = temp->nextptr;
        node_t * temp2 = front;
        while (temp2-> nextptr != temp)
            temp2 = temp2->nextptr;
        temp2->nextptr = front;
        free(temp);
        return front;
    }


    return front;

}

void front(node_t * front)
{
    printf("%d is in the front of the line.\n", front->data);
}

