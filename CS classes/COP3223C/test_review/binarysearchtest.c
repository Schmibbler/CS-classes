#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int binary_search(int * arr, int val, int left, int right);
double sqrtBinary(double val, double left, double right, int *steps);

int main (void)
{

//    int steps = 0;
//    double left = 0.0;
//    printf("Enter any number to square root:");
//    double val;
//    scanf("%lf", &val);
//    double right = val;
//    double sqrt_of_val = sqrtBinary(val, left, right, &steps);
//    printf("The homebrew square root of %.10lf is %.10lf\n", val, sqrt_of_val);
//    printf("The math.h square root of %.10lf is %.10lf\n", val, sqrt(val));
//    printf("Finding the square root took %d steps", steps);

    int arr[1000];
    for (int i = 0; i < 1000; ++i)
        arr[i] = i;

    int result = binary_search(arr, 998, 0, 1000);

    if (result == -1)
        printf("Value not found!\n");
    else
        printf("Value found at index %d\n", result);
    return 0;
}


int binary_search(int * arr, int val, int left, int right)
{
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (left == right)
            if (arr[left] == val)
                return left;
            else
                return -1;
        if (arr[mid] > val)
            right = mid - 1;
        else if (arr[mid] < val)
            left = mid + 1;
    }

}

double sqrtBinary(double val, double left, double right, int *steps)
{
    (*steps)++;
    printf("Val: %.2lf\n", val);
    printf("Left vs Right: \n%.14lf\n%.14lf\n\n", left, right);
    printf("Left * Left == %.2lf\n", (left * left));
    printf("Right * Right == %.2lf\n", (right * right));
    if (fmod((left * left), val) < 0.0000000000001 && left > 0 && right < val)
    {
        return left;
    } else if (fmod((right * right), val) < 0.0000000000001 && left > 0 && right < val)
    {
        return right;
    }


    double mid = left + ((right - left) / 2);

    if (mid * mid < val)
        return sqrtBinary(val, mid, right, steps);
    else if (mid * mid > val)
        return sqrtBinary(val, left, mid, steps);

}
