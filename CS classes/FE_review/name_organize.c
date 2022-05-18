#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 10
#define MAX_LEN 15

void display(char ** string_array, int len);
char ** alloc(int num_names, int max_name_length);
void free_array(char ** string_array, int num_names);
void swap(char * first_string, char * second_string);
void insert(char ** string_array, char * string, int * current_length);
void build_max_heap(char ** arr, int n);
void heapsort(char ** arr, int n);
void heapify(char ** arr, int n, int i);

int main (void)
{

    char ** string_array = alloc(MAX_NAMES, MAX_LEN);

    int curr_len = 0;
    insert(string_array, "zombie", &curr_len);
    insert(string_array, "zoomer", &curr_len);
    insert(string_array, "zomply", &curr_len);
    insert(string_array, "hello", &curr_len);
    insert(string_array, "hoimp", &curr_len);
    insert(string_array, "glommo", &curr_len);
    insert(string_array, "shaun", &curr_len);
    insert(string_array, "comino", &curr_len);
    insert(string_array, "apples", &curr_len);
    insert(string_array, "butter", &curr_len);

    printf("Before heapsort:\n");
    display(string_array, curr_len);
    heapsort(string_array, curr_len);
    printf("After heapsort:\n");
    display(string_array, curr_len);
    printf("Length of array is %d\n", curr_len);


    free_array(string_array, MAX_NAMES);
    return 0;
}

void heapify(char ** arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && strcmp(arr[left], arr[largest]) > 0)
        largest = left;
    if (right < n && strcmp(arr[right], arr[largest]) > 0)
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void build_max_heap(char ** arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
}

void heapsort(char ** arr, int n)
{
    build_max_heap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void insert(char ** string_array, char * string, int * current_length)
{
    strcpy(string_array[(*current_length)], string);
    (*current_length)++;
}

void swap(char * first_string, char * second_string)
{
    char temp[MAX_LEN];
    strcpy(temp, second_string);
    strcpy(second_string, first_string);
    strcpy(first_string, temp);
}

void free_array(char ** string_array, int num_names)
{
    for (int i = 0; i < num_names; i++)
        free(string_array[i]);
    free(string_array);
}

char ** alloc(int num_names, int max_name_length)
{
    char ** names_list = (char **) malloc(sizeof(char *) * num_names);
    for (int i = 0; i < num_names; i++)
        names_list[i] = (char *) malloc(sizeof(char) * max_name_length);
    return names_list;

}

void display(char ** string_array, int len)
{
    for (int i = 0; i < len; i++)
        if (string_array[i] != NULL)
            printf("%s\n", string_array[i]);
    printf("\n\n");
}
