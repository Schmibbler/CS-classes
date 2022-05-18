#include <stdio.h>
#include <stdlib.h>

void heapify(int * arr, int n, int i);
void build_max_heap(int * arr, int n);
void heapsort(int * arr, int n);
void scramble(int * arr, int n);
void display(int * arr, int n);

int partition(int * arr, int p, int r);
void quicksort(int * arr, int p, int r);

int main (void)
{
    printf("Heapsort:\n");
    int arr[20];
    scramble(arr, 20);
    display(arr, 20);
    heapsort(arr, 20);
    display(arr, 20);

    printf("Quicksort:\n");
    scramble(arr, 20);
    display(arr, 20);
    quicksort(arr, 0, 20 - 1);
    display(arr, 20);

    return 0;
}

int partition(int * arr, int p, int r)
{
    int x = arr[r];
    int i = (p - 1);

    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return (i + 1);

}
void quicksort(int * arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

void scramble(int * arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10;
}
void display(int * arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
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
