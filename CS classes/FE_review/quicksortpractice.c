#include<stdio.h>
#include<stdlib.h>
#define MAX 25

void quickSort(int * arr, int p, int r);
int partition(int * arr, int p, int r);

int main (void)
{
    int arr[MAX];
    for (int i = 0; i < MAX; ++i)
        arr[i] = rand() % 100;

    printf("Before quickSort:\n");
    for (int i = 0; i< 10; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    quickSort(arr, (int) MAX / 2, arr[MAX-1]);

    printf("After quickSort\n");

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    return 0;
}


void quickSort(int * arr, int p, int r)
{
	if (p < r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

int partition(int * arr, int p, int r)
{
	int x = arr[r]; //random pivot

	int i = (p - 1);

	for (int j = p; j < r; j++)
	{
		if (arr[j] <= x)
		{
			++i;

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
