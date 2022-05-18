#include <stdio.h>
#define SIZE 5

//Shaun Comino
//Dr. Steinberg
//COP3223 Section 5
//Small Program 6

// Function prototypes
void meanMinMax(int arr[]);
void organize(int arr[]);
void duplicate(int arr[], int arr2[]);
int locate(int arr[], int val, int size);

int main(void)
{
    // Question 1
    int arr[SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        int input;
        printf("Enter value for element %d\n", (i + 1));
        scanf("%d", &input);
        arr[i] = input;
    }
    meanMinMax(arr);

    // Question 2
    organize(arr);

    // Question 3

    int arr2[SIZE];

    printf("Duplicating...\n");
    duplicate(arr, arr2);

    printf("Values in second array:\n");
    for (int i = 0; i < SIZE; ++i)
        printf("%d ", arr2[i]);

    printf("\n");


    // Question 4

    // Gets the length of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Question prompt did not ask for user input,
    // so I am hardcoding a test case

    int val = 4;
    int result = locate(arr, val, size);
    printf("Index of '%d' (-1 means not found): %d\n", val, result);


    return 0;
}


void meanMinMax (int arr[])
{
    // Delcaring variables
    int sum;
    double mean;
    sum = 0;

    // Adds each element to 'sum'
    for (int i = 0; i < SIZE; ++i)
    {
        int element = arr[i];
        sum += element;
    }

    printf("Sum of the array is: %d\n", sum);
    printf("The mean of the array is: %.2f\n", ((double)sum / SIZE));

    // Retrieves minimum of array
    int ref = arr[0];
    for (int i = 0; i < SIZE; ++i)
        if (arr[i] < ref)
        {
            ref = arr[i];
        }
    printf("Minimum of the array is: %d\n", ref);

    // Retrieves maximum of the array
    ref = arr[0];
    for (int i = 0; i < SIZE; ++i)
    {
        if (arr[i] > ref)
            ref = arr[i];
    }
    printf("Maximum of the array is: %d\n\n", ref);


}

void organize (int arr[])
{
    // Sorts the array from least to greatest.
    for (int i = 0; i < (SIZE - 1); ++i)
    {
        for (int j = 0; j < (SIZE - i - 1); ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Displays each element in array
    for (int i = 0; i < SIZE; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Duplicates the array
void duplicate (int arr[], int arr2[])
{
    for (int i = 0; i < SIZE; ++i)
        arr2[i] = arr[i];
}

int locate (int arr[], int val, int size)
{
    // Checks every element to see if == val
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;

}
