#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void display(int * arr, int n);
void scramble(int * arr, int n);

void heapify(int * arr, int n, int i);
void heapsort(int * arr, int n);
void build_max_heap(int * arr, int n);


int main (void)
{
    printf("%d\n", 0b1111111111111111111111111111111);
    /*
    int arr[MAX];
    printf("Heapsort\n");
    scramble(arr, MAX);
    display(arr, MAX);
    heapsort(arr, MAX);
    display(arr, MAX);
    */
    return 0;
}

void display(int * arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}
void scramble(int * arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10;
}

void build_max_heap(int * arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
}

void heapsort(int * arr, int n)
{
    build_max_heap(arr, n);
    for (int i = n - 1; i >= 0; --i)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}


void heapify(int * arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
