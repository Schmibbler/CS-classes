#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s * nextptr;
} node_t;
node_t * createNode();
node_t * copyNode(node_t * node);
node_t * insertBack(node_t * head);
void display(node_t * head);
node_t * reverse(node_t * head);
node_t * sort_list(node_t * head);

int main (void)
{
    node_t * head = NULL;
    for (int i = 0; i < 10; i++)
        head = insertBack(head);


    printf("This is the linked list!\n");
    display(head);

    head = reverse(head);
    printf("(hopefully) reversed list\n");
    display(head);





//    printf("Sorting linked list...\n");
//    head = sort_list(head);
//    display(head);
//    printf("Reversing sorted list...\n");
//    head = reverse(head);
//    display(head);
//    printf("Sorting the reverse-sorted list...\n");
//    head = sort_list(head);
//    display(head);


    return 0;
}

node_t * sort_list(node_t * head)
{
    int len = 0;
    node_t * temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->nextptr;
    }

    for (int i = 0; i < len; i++)
    {
        temp = head;
        while (temp->nextptr != NULL)
        {
            if(temp->data > temp->nextptr->data)
            {
                int temp_data = temp->data;
                temp->data = temp->nextptr->data;
                temp->nextptr->data = temp->data;
            }
            temp = temp->nextptr;
        }
    }
    return head;
}

node_t * reverse(node_t * head)
{
    node_t * top = copyNode(head);
    top->nextptr = NULL;
    node_t * temp = head->nextptr;
    while (temp != NULL)
    {
        node_t * temp2 = copyNode(temp);
        temp2->nextptr = top;
        temp = temp->nextptr;
        top = temp2;
    }
    return top;
}
void display(node_t * head)
{
    node_t * temp = head;
    while (temp != NULL)
    {
        printf(" ---\n");
        printf("| %d |\n", temp->data);
        printf(" ---\n");
        temp = temp->nextptr;

    }
}

node_t * insertBack(node_t * head)
{
    if (head == NULL)
        return createNode();

    node_t * temp = head;
    while (temp->nextptr != NULL)
        temp = temp->nextptr;

    temp->nextptr = createNode();
    temp->nextptr->nextptr = NULL;
    return head;
}

node_t * createNode()
{
    node_t * new_node = (node_t *) malloc(sizeof(node_t) * 1);
    if (new_node == NULL)
    {
        printf("Yoinkly!\n");
        exit(69420);
    }

    new_node->data = rand() % 100;
    new_node->nextptr = NULL;
    return new_node;


}

node_t * copyNode(node_t * node)
{
    node_t * copied_node = (node_t *) malloc(sizeof(node_t) * 1);
    if(copied_node == NULL)
    {
        printf("Fake and gay\n");
        exit(69);
    }

    copied_node->nextptr = node->nextptr;
    copied_node->data = node->data;
    return copied_node;
}
