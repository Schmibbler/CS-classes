#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_MATCHES 100
#define MAX_ARR_SIZE 500

//int * matches_count(int * arr1, int *arr2);

void brute_force_matches(int arr1[], int arr2[]);
void linear_matches(int arr1[], int arr2[]);

int main (void)
{
    srand(time(NULL));

    int arr1[MAX_ARR_SIZE];
    int arr2[MAX_ARR_SIZE];

    int increase_by_arr1[MAX_ARR_SIZE];
    int increase_by_arr2[MAX_ARR_SIZE];

    for (int i = 0; i < MAX_ARR_SIZE; i ++)
    {
        increase_by_arr1[i] = (rand() % i) + 1;
        increase_by_arr2[i] = (rand() % i) + 1;
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

    brute_force_matches(arr1, arr2);

    linear_matches(arr1, arr2);


    return 0;

}


void brute_force_matches(int arr1[], int arr2[])
{
    printf("Brute force match search!\n");
    int matches_count = 0;
    int matches[MAX_ARR_SIZE];

    for (int i = 0; i < MAX_ARR_SIZE; ++i)
        for (int j = 0; j < MAX_ARR_SIZE; ++j)
            if (arr1[i] == arr2[j])
            {
                if (matches_count % 15 == 0)
                    printf("\n");
                matches_count++;
                matches[i] = arr1[i];
                printf("%d ", matches[i]);
            }

    printf("\n\n");
    printf("%d matches found!\n\n", matches_count);
}

void linear_matches(int arr1[], int arr2[])
{
    int matches_found = 0;
    int *matches_ptr = &matches_found;
    printf("Linear match search!\n");
    int i, j = 0;
    while (i < MAX_ARR_SIZE && j < MAX_ARR_SIZE)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        } else if (arr1[i] > arr2[j])
        {
            j++;
        } else if (arr1[i] == arr2[j])
        {
            if (*matches_ptr % 15 == 0)
                printf("\n");
            printf("%d ", arr1[i]);
            i++;
            j++;
            *matches_ptr += 1;
        }


    }
    printf("\n\n%d matches found!\n\n", matches_found);
}


