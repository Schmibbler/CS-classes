#include <stdio.h>


int binary_search(int arr[], int low, int high, int target);
int main (void)
{
    int arr[50];
    for (int i = 0; i < 50; i++)
        arr[i] = i * 2;

    int result = binary_search(arr, 0, 50, 40);

    if (result == -1)
        printf("Value not found\n");
    else
        printf("Found target at index %d\n", result);


    return 0;
}

int binary_search(int arr[], int low, int high, int target)
{
    int mid = low + ((high - low) / 2);
    if (arr[mid] < target)
        return binary_search(arr, mid + 1, high, target);
    else if (arr[mid] > target)
        return binary_search(arr, low, mid - 1, target);
    else if (arr[mid] == target)
        return mid;
}
