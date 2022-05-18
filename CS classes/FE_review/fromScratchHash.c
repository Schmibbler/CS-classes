#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 20

typedef struct {
    int data;
    int key;
} Item;

int division_method_hash(int key)
{
    return (key % SIZE);
}

int multiplication_method_hash(int key)
{
    return (int) ((double)SIZE * ((double)key * fmod(0.2331, 1.0)));
}

int main (void)
{

    Item * hash_table[SIZE];
    Item * dummyItem;
    Item * item;


    return 0;
}


Item * search(int key)
{
    int hashIndex = division_method_hash(key);
    while (hash_table[hashIndex] != NULL)
    {
        if (hash_table[hashIndex]->key == key)
            return hash_table[hashIndex];
        ++hashIndex;
        hashIndex %= SIZE;
    }
    return NULL;
}

void insert(int key, int data)
{
    Item * item = (Item *) malloc(sizeof(Item) * 1);
    item->data = data;
    item->key = key;

    int hashIndex = division_method_hash(key);

    while (hash_table[hashIndex] != NULL && hash_table[hashIndex]->key != -1)
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }
}


Item * delete_item(Item * item)
{
    int key = item->key;
    int hashIndex = division_method_hash(key);

    while (hash_table[hashIndex] != NULL)
    {
        if (hash_table[hashIndex]->key == key)
        {
            Item * temp = hash_table[hashIndex];
            hash_table[hashIndex] = dummyItem;
            return temp;
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }
    return NULL;
}








