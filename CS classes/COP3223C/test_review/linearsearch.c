#include <stdio.h>


int solution1(int * arr, int val, int size);
int solution2(int * arr, int val, int left, int right);

int main (void)
{

    int arr[50];
    for (int i = 0; i < 50; ++i)
        arr[i] = i * 2;



    return 0;
}

// Linear solution
int solution1(int * arr, int val, int size)
{

    int val_to_find = 48;
    for (int i = 0; i < size; ++i)
        if (arr[i] == val)
            return i;

    int index_of_fortyeight = solution2(arr, val_to_find, 0, 50);
    printf("Index of %d is %d\n", val_to_find, index_of_fortyeight);
    return -1;
}

int solution2(int * arr, int val, int left, int right)
{

    if (left == right)
        if(arr[left] == val)
            return left;
        else
            return -1;
    int mid = (right - left) / 2;

    if (val == arr[mid])
        return mid;

    if (arr[mid] > val)
        return solution2(arr, val, left, mid - 1);
    else
        return solution2(arr, val, mid + 1, right);

}
