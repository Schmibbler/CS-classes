#include <stdio.h>

typedef struct node_s{

    struct node_s *nextptr;
    int age;
    char name [50];

} node_t;

void display(node_t * node);
int empty(node_t *node);

int main (void)
{
    node_t *head = NULL;



    return 0;
}

void display(node_t * node)
{
    printf("Display invoked...\n");
    while (node != NULL)
    {
        printf("----------------\n");
        printf("node address is %p\n", node);
        printf("node name is %s\n", node->name);
        printf("node age is %d\n", node->age);
        printf("node nextptr points to %p\n", node->nextptr);
        printf("----------------\n");
        node = node->nextptr;
    }
}

int empty(node_t *node)
{
    printf("Empty invoked\n");
    return (node == NULL);
}
