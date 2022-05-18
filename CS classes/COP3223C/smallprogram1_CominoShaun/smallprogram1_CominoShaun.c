
#include <stdio.h>
int main()
{

    //Shaun Comino
    //Dr. Steinberg
    //COP3223 Section 5
    //Small Program 1

    //Question 1 begins
    printf("TTTTTTTTTTTTTTTTTTTTTTTTT\n");
    printf("TTTTTTTTTTTTTTTTTTTTTTTTT\n");
    printf("TTTTTTTTTTTTTTTTTTTTTTTTT\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    printf("\tTTTTTTTT\t\n");
    //Question 1 ends

    //Question 2 begins
    double startReading;
    double endReading;
    double milesTraveled;
    double compensation;

    printf("Mileage Reimbursement Calculator\n");
    printf("Enter your beginning mileage reading\n");
    scanf("%lf", &startReading);
    printf("Enter your ending mileage reading\n");
    scanf("%lf", &endReading);
    milesTraveled = endReading - startReading;
    printf("You traveled %.2f miles\n", milesTraveled);
    compensation = milesTraveled * 0.35;
    printf("At $0.35 per mile, your compensation is $%.2f\n\n", compensation);
    //Question 2 ends

    //Question 3 begins
    int hours;
    int minutes;
    double time;
    double temperature;

    printf("Oh no, your power went out while you were away! You better find out what the freezer temperature is!\n");
    printf("Enter how many hours and minutes it has been since the power outage. First enter hours, then minutes.\n");

    printf("Enter hours:\n");
    scanf("%d", &hours);

    printf("Enter minutes:\n");
    scanf("%d", &minutes);

    time = hours + (minutes / 60);
    temperature = ((4 * (time * time)) / (time + 2)) - 20;

    printf("The temperature of your freezer is %.2f degrees Celcius\n\n", temperature);
    //Question 3 ends

    //Question 4 begins
    const double pi = 3.14159;
    double radius;
    double diameter;
    double circum;
    double area;

    printf("Enter the radius of your circle:\n");
    scanf("%lf", &radius);

    diameter = radius * 2;
    circum = diameter * pi;
    area = pi * (radius * radius);

    printf("The diameter of your circle is %.2f\n", diameter);
    printf("The circumference of your circle is %.2f\n", circum);
    printf("The area of your circle is %.2f\n", area);
    //Question 4 ends
    return 0;
}
