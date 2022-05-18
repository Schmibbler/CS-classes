#include <stdio.h>
#include <math.h>
//Shaun Comino
//Dr. Steinberg
//COP3223 Section 5
//Small Program 5

// Function prototypes
void Change(double *ptr1, double *ptr2);
void MultTable(int *rows, int *columns);
void Maximum(int *num1, int *num2);
void IncrementUpdate(int *val);

int main (void)
{
    // Question 1
    double paid;
    double due;
    double *paidptr = &paid;
    double *dueptr = &due;

    printf("Enter amount paid: \n");
    scanf("%lf", &paid);

    printf("Enter amount due: \n");
    scanf("%lf", &due);

    // Question 1 function call
    Change(paidptr, dueptr);

    // Question 2
    int rows;
    int columns;
    int *rowsptr = &rows;
    int *columnsptr = &columns;

    printf("Enter the amount of rows to display: \n");
    scanf("%d", &rows);

    printf("Enter the amount of columns to display: \n");
    scanf("%d", &columns);

    // Question 2 function call
    MultTable(rowsptr, columnsptr);

    // Question 3
    int num1;
    int num2;
    int *num1ptr = &num1;
    int *num2ptr = &num2;

    printf("Enter the first number: \n");
    scanf("%d", &num1);

    printf("Enter the second number: \n");
    scanf("%d", &num2);

    // Question 3 function call
    Maximum(num1ptr, num2ptr);

    // Question 4
    int val = 0;
    int *valptr = &val;
    printf("Before calling IncrementUpdate\n");
    printf("val = %d\n", val);

    // Question 4 function call
    IncrementUpdate(valptr);

    printf("After calling IncrementUpdate\n");
    printf("val = %d\n", val);
}

void Change(double *paid, double *due)
{
    // Change is the amount paid - amount due
    double difference;
    difference = (*paid - *due) * 100;
    int change = (int)difference;
    printf("Change: %.2f\n", ((double)change / 100));

    int remainder;
    int dollars;
    int quarters;
    int dimes;
    int nickels;
    int pennies;

    for (int i = 0; i < 5; ++i)
    {
        // USes the iterations (i) to determine which currency
        // to return.
        // (i = 0) Return Dollars -> (i = 1) Return Quarters... and so forth.
        switch (i)
        {
            // Checks which iteration the loop is on.
            case 0:
                dollars = change / 100;
                printf("Dollars: %d\n", dollars);
                remainder = change % 100;
                break;

            case 1:
                quarters = remainder / 25;
                printf("Quarters: %d\n", quarters);
                remainder = remainder % 25;
                break;

            case 2:
                dimes = remainder / 10;
                printf("Dimes: %d\n", dimes);
                remainder = remainder % 10;
                break;

            case 3:
                nickels = remainder / 5;
                printf("Nickels: %d\n", nickels);
                remainder = remainder % 5;
                break;

            case 4:
                pennies = remainder / 1;
                printf("Pennies: %d\n", pennies);
                remainder = remainder % 1;
                break;

            default:
                break;
        }
    }
}

void MultTable(int *rows, int *columns)
{
    int increment = 1;
    // Iterates for amount of rows
    for (int i = 0; i < *rows; ++i)
    {
        // numCol means the number at the given column
        int numCol = increment;

        // Iterates for amount of columns
        for (int i = 0; i < *columns; ++i)
        {
            printf("\t%d", numCol);
            numCol = numCol + increment;
        }
        printf("\n");
        increment++;
    }
}

void Maximum(int *num1, int *num2)
{
    // Compares the two
    if (*num1 > *num2)
    {
        printf("%d is greater than %d\n\n", *num1, *num2);
    }
    else if (*num1 < *num2)
    {
        printf("%d is greater than %d\n\n", *num2, *num1);
    }
    else if (*num1 == *num2)
    {
        printf("You baffoon, this function was meant to print\n");
        printf("the maximum of two values, but you gave\n");
        printf("values that were entirely equal...\n\n");
    }
    else
    {
        // This is here just for aesthetics
    }
}

void IncrementUpdate(int *val)
{
    // Doesn't assign a value to choice... yet
    int choice;
    *val += 1;
    printf("Updating val now...\n");
    printf("Would you like to update...\n");
    printf("Enter 0 if you would like to update again, ");
    printf("Anything else will exit the update.\n");
    printf("Option: ");
    scanf("%d", &choice);
    printf("\n");
    if (choice == 0)
    {
        // Calls the function again using recursion
        // This takes a pointer argument
        IncrementUpdate(val);
    }
    else
    {
        printf("Val is done updating\n");
    }
}


