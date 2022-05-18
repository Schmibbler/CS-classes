#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 15
void display(int * arr, int length);
void bubblesort(int * arr, int n);
void rand_arr(int * arr, int length);
void insertion_sort(int * arr, int n);
void selection_sort(int * arr, int length);

// Merge sort
void merge(int * arr, int p, int q, int r);
void mergesort(int * arr, int p, int r);

int main (void)
{
    srand(time(NULL));
    int arr[LENGTH];


    printf("Insertion sort:\n");
    rand_arr(arr, LENGTH);
    display(arr, LENGTH);
    insertion_sort(arr, LENGTH);
    display(arr, LENGTH);

    printf("Bubble sort:\n");
    rand_arr(arr, LENGTH);
    display(arr, LENGTH);
    bubblesort(arr, LENGTH);
    display(arr, LENGTH);

    printf("Selection sort:\n");
    rand_arr(arr, LENGTH);
    display(arr, LENGTH);
    selection_sort(arr, LENGTH);
    display(arr, LENGTH);




    return 0;
}

void merge(int * arr, int p, int q, int r)
{
    // Declare lengths of the two subarrays
    n1 = q - p + 1;
    n2 = r - q;

    // Allocate the two subarrays
    int * leftarr = (int *) malloc(sizeof(int) * n1);
    int * rightarr = (int *) malloc(sizeof(int) * n2);

    // Copy the values into the subarrays
    for (int i = 0; i < n1; ++i)
        leftarr[i] = arr[p + i];
    for (int i = 0; i < n2; ++i)
        rightarr[i] = arr[p + q + 1];






    free(leftarr);
    free(rightarr);

}

void mergesort(int * arr, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(arr, p, q);
        mergesort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}



void selection_sort(int * arr, int length)
{
    int min;
    for (int i = 0; i < length; ++i)
    {
        min = i;
        for (int j = i; j < length; ++j)
            if (arr[j] < arr[min])
                min = j;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void rand_arr(int * arr, int length)
{
    for (int i = 0; i < length; ++i)
        arr[i] = rand() % 10;
}

void display(int * arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

void bubblesort(int * arr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void insertion_sort(int * arr, int n)
{
    int temp;
    int iter;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            iter = i;
            while (iter > 0)
            {
                if (arr[iter] < arr[iter - 1])
                {
                    temp = arr[iter];
                    arr[iter] = arr[iter - 1];
                    arr[iter - 1] = temp;
                }
                iter--;
            }

        }
    }
}

