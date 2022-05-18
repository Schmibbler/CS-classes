#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int heapMaximum(int * arr);
int heapExtractMax(int * arr, int * size);
void heapIncreaseKey(int * arr, int i, int k);
void heapInsert(int * arr, int k, int * size, int max);
void heapify(int * arr, int n, int i);

int main (void)
{
    int size = 0;
    int arr[MAX];
    for (int i = 0; i < 10; i++)
        heapInsert(arr, rand() % 100, &size, MAX);




    return 0;
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

int heapMaximum(int * arr)
{
    return arr[0];
}

void heapInsert(int * arr, int k, int * size, int max)
{
    if (*size == max) {
        printf("Overflow!\n");
        exit(69);
    } else {
        *size += 1;
        arr[*size - 1] = k;
        int i = *size;

        while (i > 0 && arr[i] > arr[i/2]) {
            int temp;
            temp = arr[i];
            arr[i] = arr[i/2];
            arr[i/2] = temp;
            i /= 2;
        }
    }
}

int heapExtractMax(int * arr, int * size) {

    if (*size < 1) {
        printf("Underflow...\n");
    return -1;
    }

    int max = arr[0];

    arr[0] = arr[*size - 1];

    *size -= 1;
    heapify(arr, 0, 0);
    return max;
}
