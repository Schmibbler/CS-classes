#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_TARGET_SIZE 25
#define MAX_ARR_SIZE 10000

int sum_to_target(int arr1[], int arr2[], int val);

int main (void)
{
    srand(time(NULL));
    int arr1[MAX_ARR_SIZE];
    int arr2[MAX_ARR_SIZE];

    int increase_by_arr1[MAX_ARR_SIZE];
    int increase_by_arr2[MAX_ARR_SIZE];

    for (int i = 0; i < MAX_ARR_SIZE; i ++)
    {
        increase_by_arr1[i] = (rand() % 2) + 1;
        increase_by_arr2[i] = (rand() % 2) + 1;
    }

    for (int i = 0; i < MAX_ARR_SIZE; i++)
    {
        if (i != 0)
            arr1[i] = arr1[i - 1] + increase_by_arr1[i];
        else
            arr1[i] = 0;
    }

    for (int i = 0; i < MAX_ARR_SIZE; i++)
    {
        if (i != 0)
            arr2[i] = arr2[i - 1] + increase_by_arr2[i];
        else
            arr2[i] = 0;
    }

    int targets[MAX_TARGET_SIZE];

    int targets_increase_by[MAX_TARGET_SIZE];
    for (int i = 0; i < MAX_TARGET_SIZE; i++)
        targets_increase_by[i] = (rand() % 50) + 1;

    for (int i = 0; i < MAX_TARGET_SIZE; i++)
    {
        if (i == 0)
        {
            targets[i] = 1;
        }
        else
        {
            targets[i] = targets[i - 1] + targets_increase_by[i];
        }
    }


    printf("Presented is an array of target values\n");
    printf("The sum of each value can be described by two large constant arrays\n");
    printf("of random integers.\n");
    printf("If there exists one constant in each random integer array that add\n");
    printf("to a value in the target value array, each will be shown\n\n");

    printf("Target values:\n");


    for (int i = 0; i < MAX_TARGET_SIZE; i++)
    {
        if (i % 5 == 0)
            printf("\n");
        printf("%d ", targets[i]);
    }
    printf("\n\n");

    for (int i = 0; i < MAX_TARGET_SIZE; i++)
        sum_to_target(arr1, arr2, targets[i]);

}

int sum_to_target(int arr1[], int arr2[], int val)
{
    int i = 0;
    int j = MAX_SIZE;

    while (i <= MAX_SIZE && j >= 1)
    {
        if (arr1[i] + arr2[j] == val)
        {
            printf("%d equals %d plus %d\n", val, arr2[j], arr1[i]);
            return 1;
        }
        else if (arr1[i] + arr2[j] < val)
            i++;
        else
            j++;
    }

    printf("%d: none!\n", val);
    return 0;


}
