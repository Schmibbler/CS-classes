int main()
{
    //problem 1
    printf("C Language is cool!\n");

    //problem 2
    int x;
    int y;

    //Collect input
    printf("Input height\n");
    scanf("%d", &x);

    printf("Input width\n");
    scanf("%d", &y);

    int perimeter;
    int area;

    perimeter = (2 * y) + (2 * x);
    area = (x * y);

    printf("Your perimeter is %d\n", perimeter);
    printf("Your area is %d\n", area);

    //Problem 3
    int year;
    int days;
    int weeks;

    printf("Enter the number of years: \n");
    scanf("%d", &year);

    days = year * 365;

    weeks = year * 52;

    printf("Days = %d\n", days);
    printf("Weeks = %d\n", weeks);

    //Problem 4

    double x1 = 1.5;
    double x2 = 4.5;
    double y1 = 1.1;
    double y2 = 5.3;
    double slope;

    slope = (y2 - y1) / (x2 - x1);
    printf("Slope is %f\n", slope);

    //Problem 5

    double a = 4.2;
    double b = 3.1;

    double result = (((a * a * a * a) + (b * b))/4) - ((1)/((a * a * a * a) + (b * b)));
    printf("Result is %f\n", result);

    //Problem 6

    result = ((a * a * a * a) + (b * b)) / (b * b * b * b * b) + b;

    printf("Result is %f\n", result);

    //Problem 7

    result = ((a * a + b) / b) / ((b * b * b) - a / b);
    printf("Result is %f\n", result);

    //Problem 8

    //WARNING: "A" != 'A'

    char ltr = 'A';
    int num = (int) ltr;
    printf("Letter A in decimal is = %d\n", num);

    char ltr2 = 'a';
    int num2 = (int) ltr2;
    printf("Letter a in decimal is = %d\n", num2);
    return 0;
}
