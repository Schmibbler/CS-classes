
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

/*
This file is a hash table implementing chaining
for collision resolution
*/
typedef struct node_s {
    int data;
    struct node_s * next_in_chain;
} node_t;

void insert(node_t ** hash_table, int data, int m);
node_t * create_node(int data);
void display(node_t ** hash_table, int n);
void count_collisions(node_t ** hash_table, int n, int * count);
int exists(node_t ** hash_table, int data, int m);
int hash_function(int k, int m);
void delete_item(node_t ** hash_table, int data, int m);

int main (void)
{


    node_t ** hash_table = (node_t **) malloc(sizeof(node_t *) * MAX);
    for (int i = 0; i < MAX; ++i)
        hash_table[i] = NULL;

    int m = 13;

    insert(hash_table, 12, m);
    insert(hash_table, 900, m);
    insert(hash_table, 14, m);
    insert(hash_table, 15, m);
    insert(hash_table, 0, m);
    insert(hash_table, 0, m);
    insert(hash_table, 200, m);
    insert(hash_table, 233, m);

    display(hash_table, MAX);

    printf("Inserting many values...\n");

    for (int i = 0; i < 25; i++)
        insert(hash_table, rand() % 100, m);

    display(hash_table, MAX);
    int collision_count = 0;
    count_collisions(hash_table, MAX, &collision_count);

    printf("There are a total of %d collisions in this hash table\n", collision_count);

    printf("Does 900 exist in the hash table?\n");
    printf("%d\n", exists(hash_table, 900, m));
    printf("Does 9001 exist in the has table?\n");
    printf("%d\n", exists(hash_table, 9001, m));

    printf("Deleting item with data 900\n");
    delete_item(hash_table, 900, m);
    display(hash_table, MAX);
    printf("Deleting items with data: 23, 1, 200, 14\n");
    delete_item(hash_table, 23, m);
    delete_item(hash_table, 1, m);
    delete_item(hash_table, 200, m);
    delete_item(hash_table, 14, m);
    display(hash_table, MAX);

}

void delete_item(node_t ** hash_table, int data, int m)
{
    if (!exists(hash_table, data, m))
    {
        printf("%d does not exist in the hash table!\n", data);
        return;
    }

    int key = hash_function(data, m);
    node_t * temp = hash_table[key];
    if (temp->data == data)
    {
        temp = temp->next_in_chain;
        return;
    } else
    {
        while (temp != NULL)
        {
            if (temp->next_in_chain->data == data)
            {
                temp->next_in_chain = temp->next_in_chain->next_in_chain;
            }
            temp = temp->next_in_chain;
        }
    }
}

int exists(node_t ** hash_table, int data, int m)
{
    int key = hash_function(data, m);
    if (hash_table[key] != NULL && hash_table[key]->next_in_chain != NULL)
    {
        if (hash_table[key]->data == data)
            return 1;
        else
        {
            node_t * temp = hash_table[key];
            while (temp != NULL)
            {
                if (temp->data == data)
                    return 1;
                temp = temp->next_in_chain;
            }
            return 0;
        }
    }
    else if (hash_table[key] == NULL)
        return 0;
}

void count_collisions(node_t ** hash_table, int n, int * count)
{
    for (int i = 0; i < n; i++)
    {
        if (hash_table[i] != NULL && hash_table[i]->next_in_chain != NULL)
        {
            node_t * temp = hash_table[i];
            while (temp != NULL)
            {
                temp = temp->next_in_chain;
                (*count)++;
            }
        }
    }
}

void display(node_t ** hash_table, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (hash_table[i] != NULL && hash_table[i]->next_in_chain == NULL)
            printf("%d ", hash_table[i]->data);
        else if (hash_table[i] != NULL && hash_table[i]->next_in_chain != NULL)
        {
            node_t * temp = hash_table[i];
            while (temp != NULL)
            {
                printf("%d ", temp->data);
                temp = temp->next_in_chain;
            }
        }
    }
    printf("\n\n");
}



// Hash function of k mod m
int hash_function(int k, int m)
{
   return (k % m);
}

// Solving collisions with chaining
void insert(node_t ** hash_table, int data, int m)
{
    int key = hash_function(data, m);
    if (hash_table[key] != NULL)
    {
        node_t * temp = hash_table[key];
        while (temp->next_in_chain != NULL)
            temp = temp->next_in_chain;
        temp->next_in_chain = create_node(data);
    }
    else
        hash_table[key] = create_node(data);
}

node_t * create_node(int data)
{
    node_t * node = (node_t *) malloc(sizeof(node_t) * 1);
    node->data = data;
    node->next_in_chain = NULL;
    return node;
}
