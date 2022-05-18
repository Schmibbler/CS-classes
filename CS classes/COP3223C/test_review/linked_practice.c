#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *nextptr;
} node_t;

int empty(node_t * head);
node_t * insert(node_t * head, int data);
node_t * createNode();
void display(node_t * head);
node_t * search(node_t * head, int num);

node_t * delete_node(node_t * head, node_t * address_of_node);


int main(void)
{



    /*
        |=====|
        |   3 |
        |=====|
           ||
           \/
        |=====|
        |  11 |
        |=====|
           ||
           \/
        |=====|
        |  90 |
        |=====|
           ||
           \/
        |=====|
        |  12 |
        |=====|
           ||
           \/
          NULL

    */

    node_t *head = NULL;

    if (empty(head))
        printf("Empty...\n");
    else
        printf("There is data...\n");

    for (int i = 0; i < 6; i++)
        head = insert(head, i+1);


    display(head);
//
//
//    int num = 9;
//
//    printf("Searching for node in list...\n");
//
//    node_t * found_node;
//
//    found_node = search(head, num);
//
//    if (found_node == NULL)
//        printf("Didn't find that node...\n");
//    else
//        printf("Found the node with data %d at %p\n", found_node->data, found_node);
//
//    head = delete_node(head, found_node);
//
//    printf("New list is the following...\n");
//    display(head);


    return 0;
}

int empty(node_t * head)
{
    return (head == NULL);
}

node_t * insert(node_t * head, int data)
{
    if(empty(head))
    {
        head = createNode();
        head->data = data;
        head->nextptr = NULL;
        return head;
    }

    node_t * node = head;

    while(node->nextptr != NULL)
        node = node->nextptr;

    node_t *new_node = createNode();
    new_node->nextptr = NULL;
    new_node->data = rand() % 10;
    node->nextptr = new_node;
    return head;

}

void display(node_t * head)
{
    node_t * node = head;

    while(node->nextptr != NULL)
    {
        printf("------\n");
        printf("%d\n", node->data);
        printf("------\n");
        node = node->nextptr;
    }
}

node_t * search(node_t *head, int num)
{
    node_t *node;
    node = head;

    while(node->nextptr != NULL)
    {
        if(node->data == num)
            return node;
        node = node->nextptr;
    }



    return NULL;
}

node_t * createNode()
{
    node_t *node = (node_t *) malloc(sizeof(node_t) * 1);
    return node;
}

node_t * delete_node(node_t *head, node_t * address_of_node)
{
    node_t * temp;
    node_t * node;
    node = head;

    if (address_of_node == head)
    {
        temp = head;
        head = node->nextptr;
        free(temp);
        return head;
    }
    printf("Removing node of address %p with value %d from list...\n", address_of_node, address_of_node->data);

    while(node->nextptr != NULL)
    {
        if (node->nextptr == address_of_node)
        {
            if (node->nextptr->nextptr == NULL)
            {
                free(node->nextptr);
                node->nextptr = NULL;
                return head;

            }
            printf("Found node with address %p\n", node->nextptr);
            temp = node->nextptr;
            node->nextptr = node->nextptr->nextptr;
            free(temp);
            return head;
        }
        node = node->nextptr;
    }
    printf("Didn't find that node\n");
    return head;


}

