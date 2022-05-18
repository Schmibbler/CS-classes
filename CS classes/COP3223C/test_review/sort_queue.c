#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * nextptr;
} node_t;

node_t * createNode();
node_t * enqueue(node_t * front);
node_t * dequeue(node_t * front);

void display(node_t * front);
int isEmpty(node_t * front);
void swap(node_t * node1, node_t * node2);
node_t * sort_queue_asc(node_t * front);
node_t * sort_queue_desc(node_t * front);
void * peek(node_t * front);
node_t * reverseQueue(node_t * front);

int main (void)
{
    node_t * front = NULL;

    for (int i = 0; i < 50; i++)
        front = enqueue(front);
    printf("Displaying fresh queue!\n");
    display(front);

    for (int i = 0; i < 5; i++)
        front = dequeue(front);

    printf("Displaying queue after removals!\n");
    display(front);

    printf("Attempting to reverse the queue!\n");
    front = reverseQueue(front);

//    printf("Attempting to sort the queue...\n");
//    front = sort_queue_asc(front);
//    printf("Displaying after sorting the queue in ascending order!\n");
//    display(front);
//    printf("Displaying after sorting the queue in descending order!\n");
//    front = sort_queue_desc(front);
//    display(front);
//    peek(front);


    return 0;
}

node_t * reverseQueue(node_t * front)
{




}

void * peek(node_t * front)
{
    printf("The node at the front of the queue is:\n");
    printf(" ---\n");
    printf("| %d |\n", front->data);
    printf(" ---\n");
}
node_t * sort_queue_desc(node_t * front)
{
    if (isEmpty(front))
    {
        printf("Nothing to sort!\n");
        return NULL;
    }
    if(front->nextptr == NULL)
    {
        printf("Only one node!\n");
        return front;
    }

    int queue_count = 1;

    node_t * temp = front->nextptr;
    while (temp->nextptr != front)
    {
        queue_count++;
        temp = temp->nextptr;
    }

    for (int i = 0; i < queue_count; i++)
    {
        temp = front;
        while (temp->nextptr != front)
        {
            if (temp->data < temp->nextptr->data)
                swap(temp, temp->nextptr);
            temp = temp->nextptr;
        }
    }

    return front;

}

node_t * sort_queue_asc(node_t * front)
{
    if (isEmpty(front))
    {
        printf("Nothing to sort!\n");
        return NULL;
    }
    if(front->nextptr == NULL)
    {
        printf("Only one node!\n");
        return front;
    }

    int queue_count = 1;

    node_t * temp = front->nextptr;
    while (temp->nextptr != front)
    {
        queue_count++;
        temp = temp->nextptr;
    }

    for (int i = 0; i < queue_count; i++)
    {
        temp = front;
        while (temp->nextptr != front)
        {
            if (temp->data > temp->nextptr->data)
                swap(temp, temp->nextptr);
            temp = temp->nextptr;
        }
    }

    return front;

}

void swap(node_t * node1, node_t * node2)
{
    int temp_data = node1->data;
    node1->data = node2->data;
    node2->data = temp_data;
}

node_t * dequeue(node_t * front)
{
    if (isEmpty(front))
    {
        printf("Nothing to remove!\n");
        return NULL;
    }
    if (front->nextptr == NULL)
    {
        printf("One node to remove!\n");
        free(front);
        return NULL;
    }

    node_t * temp = front;
    front = front->nextptr;
    node_t * temp2 = front;
    while (temp2->nextptr != temp)
        temp2 = temp2->nextptr;
    temp2->nextptr = temp2->nextptr->nextptr;
    free(temp);
    return front;
}

int isEmpty(node_t * front)
{
    return (front == NULL);
}
void display(node_t * front)
{
    if (isEmpty(front))
    {
        printf("No queue to display!\n");
        return;
    }

    printf(" ---\n");
    printf("| %d |\n", front->data);
    printf(" ---\n");
    node_t * temp = front->nextptr;
    while (temp->nextptr != front)
    {
        printf(" ---\n");
        printf("| %d |\n", temp->data);
        printf(" ---\n");
        temp = temp->nextptr;
    }

}

node_t * enqueue(node_t * front)
{
    if (isEmpty(front))
    {
        printf("Creating new queue...\n");
        front = createNode();
        front->nextptr = front;
        return front;
    }
    if (front->nextptr == front)
    {
        node_t * new_node = createNode();
        new_node->nextptr = front;
        front->nextptr = new_node;
        return front;
    }

    node_t * temp = front->nextptr;
    while(temp->nextptr != front)
        temp = temp->nextptr;
    temp->nextptr = createNode();
    temp->nextptr->nextptr = front;
    return front;
}

node_t * createNode()
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);

    if (new_node == NULL)
    {
        printf("Naughty naughty malloc!\n");
        exit(1);
    }

    new_node->nextptr = NULL;
    new_node->data = rand () % 50;
    return new_node;

}
