#include<stdio.h>

//Shaun Comino
//Dr. Steinberg
//COP3223 Section 5
//Small Program 3

//Question 1 function prototype
void Coordinates(double xVal, double yVal);

//Question 2 function prototype
void Hurricane(double windSpeed);

//Question 3 function prototype
void Menu();

//Question 4 function prototype
void NumSolutions();


int main(void)
{

    //Question 1
    //Declaring user input doubles
    double x;
    double y;

    //Informing user of input purpose
    printf("Where is your coordinate at?\n");

    //Collects x & y double values
    printf("Enter in the x value of the coordinate:\n");
    scanf("%lf", &x);
    printf("Enter in the y value of the coordinate:\n");
    scanf("%lf", &y);

    //Question 1 function call
    Coordinates(x, y);

    //Question 2
    double windVelocity;

    //Collecting windSpeed with user input
    printf("Enter the wind velocity:\n");
    scanf("%lf", &windVelocity);

    //Question 2 function call
    Hurricane(windVelocity);

    //Question 3 function call
    Menu();

    //Question 4 function call
    NumSolutions();

}

void Coordinates(double x, double y)
{

    //Relational operators checking where the point is
    if ((x < 0) && (y < 0))
        printf("Your point is in Quadrant III\n");

    if ((x < 0) && (y > 0))
        printf("Your point is in Quadrant II\n");

    if ((x > 0) && (y > 0))
        printf("Your point is in Quadrant I\n");

    if ((x > 0) && (y < 0))
        printf("Your point is in Quadrant IV\n");

    if ((x == 0) && (y == 0))
        printf("Your point is the origin\n");

    if ((x == 0) && (y != 0))
        printf("Your point is on the y-axis\n");

    if ((x != 0) && (y == 0))
        printf("Your point is on the x-axis\n");

}


void Hurricane(double windSpeed)
{

    //Relational operators checking windSpeed and
    //printing respective hurricane category
    if (windSpeed <= 95)
        printf("Category 1\n");

    if ((windSpeed > 95) && (windSpeed <= 110))
        printf("Category 2\n");

    if ((windSpeed > 110) && (windSpeed <= 129))
        printf("Category 3\n");

    if ((windSpeed > 129) && (windSpeed <= 156))
        printf("Category 4\n");

    if ((windSpeed > 156))
        printf("Category 5\n");

}



void Menu()
{
    //Int assigned with user input later on
    int buttonPressed;

    //Setting up user input GUI
    printf("*****************\n");
    printf("Select an option\n");
    printf("1: Blue Button\n");
    printf("2: Green Button\n");
    printf("3: Red Button\n");
    printf("4: Yellow Button\n");
    printf("*****************\n");
    //If only GUIs were this simple...

    //Assigns user input to buttonPressed
    scanf("%d", &buttonPressed);

    //Reads and checks user input
    switch (buttonPressed)
    {

    //Each case checks if buttonPressed == case "x"
    //Where "x" is an integer [1,4]
    case 1:
        printf("Blue Button pressed\n");
        break;
    case 2:
        printf("Green Button pressed\n");
        break;
    case 3:
        printf("Red Button pressed\n");
        break;
    case 4:
        printf("Yellow Button pressed\n");

    }

}



void NumSolutions()
{
    //declaring a, b, c for user input
    double a;
    double b;
    double c;

    //Declaring discriminant variable
    double discrim;

    //Collecting 'a' value
    printf("Enter 'a' value:\n");
    scanf("%lf", &a);

    //Collecting 'b' value
    printf("Enter 'b' value:\n");
    scanf("%lf", &b);

    //Collecting 'c' value
    printf("Enter 'c' value:\n");
    scanf("%lf", &c);

    //Discriminant formula
    discrim = (b * b) - (4 * (a * c));

    //Outputting discrim value to user
    printf("Your function's discriminant value is %.2f\n", discrim);

    /*
    Checking the amount of solutions the
    function has based on the discriminant
    */
    if (discrim < 0)
        printf("Your function has no solutions\n");

    if (discrim > 0)
        printf("Your function has two solutions\n");

    if (discrim == 0)
        printf("Your function has one solution\n");

}

