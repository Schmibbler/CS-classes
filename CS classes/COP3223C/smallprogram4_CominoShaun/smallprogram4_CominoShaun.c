#include <stdio.h>
//Shaun Comino
//Dr. Steinberg
//COP3223 Section 5
//Small Program 4

// Function prototypes
void Triangle();
void AdvancedMenu();
int Fibonacci(int n);
void CountdownTwo();

int main (void)
{
    // Question 1 function call
    Triangle();

    // Question 2 function call
    AdvancedMenu();

    // Question 3

    // Generating user input
    int n;
    printf("Enter the nth value of the fibonacci ");
    printf("sequence you wish to see.\n");
    printf("Must be 2 or greater\n");
    scanf("%d", &n);

    // Error handling, if entered input < 2
    if (n < 2)
    {
        printf("Error; must 2 or greater\n");
    }
    else
    {
        int fibonacci_value_at_n;

        // Question 3 function call
        fibonacci_value_at_n = Fibonacci(n);
        printf("The fibonacci value at n = %d is %d\n\n", n, fibonacci_value_at_n);
    }

    // Question 4 function call
    CountdownTwo();

    return 0;
}


void Triangle()
{
    // Input from user specifying the number of rows
    int rows;
    printf("Enter the number of rows to display: \n");
    scanf("%d", &rows);

    // Error handling
    if (rows < 3)
    {
        printf("Input must be at least 3\n");
        return;
    }
    int stars = 1;


    // Prints more '*' based on the row
    for (int i = 0; i < rows; ++i)
    {
        for (int i = 0; i < stars; ++i)
        {
            printf("*");
        }
        printf("\n");

        // Increments stars for next row
        stars += 1;
    }
}


void AdvancedMenu()
{
    // inputCount = 0, because user hasn't input anything
    int inputCount;
    inputCount = 0;

    while (inputCount < 2)
    {
        int input;

        // Avoids reprinting menu by checking inputCount
        if (inputCount == 0)
        {
            printf("1. Blue Button \n");
            printf("2. Green Button \n");
            printf("3. Red Button \n");
            printf("4. Yellow Button \n");
            printf("5. Exit\n");
            printf("Select an input: \n");
        }


        scanf("%d", &input);

        // Switch statement. Case exists for each menu option
        switch (input)
        {
            case 1:
                printf("Blue Button Pressed\n\n");
                break;
            case 2:
                printf("Green Button Pressed\n\n");
                break;
            case 3:
                printf("Red Button Pressed\n\n");
                break;
            case 4:
                printf("Yellow Button Pressed\n\n");
                break;
            case 5:
                inputCount = 2;
                printf("Exiting Menu...\n\n");
                break;
            default:
                break;
        }

        // Increment for while loop
        inputCount++;

        // Prompts user to input again
        if (inputCount < 2)
            printf("Enter another input: \n");

    }
}


int Fibonacci(int n)
{

    // Declaring variables that will be updated in for loop
    int f1;
    int f2;

    // Values of sequence at n = 0 and n = 1;
    f1 = 0;
    f2 = 1;

    // Calculates sequence n times
    for (int i = 0; i < n - 1; ++i)
    {
        // This is the fibonacci sequence formula
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;

        /*
        printf("%d ", f3);
        Would print the sequence
        But it's unecessary
        */

    }

    printf("\n");
    int fibonacci_value_at_n = f2;

    // Returns value at n
    return fibonacci_value_at_n;

}

void CountdownTwo()
{
    // Number to count down from
    int downFrom;
    printf("Enter a number to count down by 2 from: ");

    // Input from user
    scanf("%d", &downFrom);
    printf("%d\n", downFrom);

    int x = downFrom;

    // Iterates (downFrom / 2) times, because
    // it counts down by 2

    for (int i = 0; i < (downFrom / 2); ++i)
    {
        // Subtract 2 from previous number
        x = x - 2;
        printf("%d\n", x);
    }
}



