#include <stdio.h>
#include <math.h>

//Function prototypes
double Hypotenuse(double a, double b);
void ParkingCharge();
void Population();
double FactorialApprox(int intArg);

int main(void)
{
    /*
    Shaun Comino
    Dr. Steinberg
    COP3223 Section 5
    Small Program 2
    */

    //Question 1
    //Declaring sides of triangle
    double a;
    double b;

    //Assigning triangle side lengths
    printf("Enter the 'a' length for the triangle \n");
    scanf("%lf", &a);
    printf("Enter the 'b' length for the triangle \n");
    scanf(" %lf", &b);

    double hypotenuse = Hypotenuse(a, b);
    printf("Hypotenuse value for this triangle is: %f \n", hypotenuse);

    //Question 2
    ParkingCharge();

    //Question 3
    Population();

    //Question 4
    int intArg;

    //Passing in intArg as function argument
    printf("Enter the integer to factorial: \n");
    scanf("%d", &intArg);

    //Prints returned result
    double factorial;
    factorial = FactorialApprox(intArg);
    printf("Factorial result is: %f\n", factorial);

    return 0;

}

//Question 1 function
double Hypotenuse(double a, double b)
{

    double hypotenuse;
    hypotenuse = sqrt((a * a) + (b * b));
    return hypotenuse;

}

//Question 2 function
void ParkingCharge()
{

    //Asking for "hours" input
    double hours;
    double cost;
    printf("Enter the amount of hours you plan to leave you car parked: \n");
    scanf("%lf", &hours);

    //Calculates the cost to park
    cost = 2.49 * hours;
    printf("Your total hours parked are: \n%.2f \n", hours);
    printf("Therefore your total cost for parking is: \n$%.2lf \n", cost);

}

//Question 3 function
void Population()
{

    double population;
    double years;
    double yearAfter1990;

    //Year after 1990 NOT years. Years after will return negative value
    printf("Enter the year after 1990: \n");
    scanf("%lf", &yearAfter1990);

    //Breaks the year entered down into years after
    years = yearAfter1990 - 1990;

    //Passes in years after 1990 and prints the truncated result
    population = 52.966 + (2.184 * years);
    printf("Predicted population for %.0f is %.2f thousand people\n", yearAfter1990, population);

}

//Question 4 function
double FactorialApprox(intArg)
{

    //Declaring pi constant and end result
    const double PI = 3.14159265;
    double factorial;

    //Passing in intArg to Gosper's formula
    factorial = pow(intArg, intArg) * exp(-intArg) * sqrt( ((2 * intArg) + (1.0/3.0)) * PI );

    //Returns the result
    return factorial;

}
