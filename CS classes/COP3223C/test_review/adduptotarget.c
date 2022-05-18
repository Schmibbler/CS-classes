#include <stdio.h>

void reverseInputWords(int n);
int factorial (int n);

int main (void)
{

    int n = 1000;

//    printf("Enter %d words to reverse\n", n);
//    reverseInputWords(n);
//

    int result = factorial(n);

    printf("%d! is equal to %d\n", n, factorial(n));

    return 0;
}



int factorial (int n)
{
    int answer;
    if (n == 0)
        answer = 1;
    else
        answer = n * factorial(n - 1);
    return answer;
}

void reverseInputWords(int n)
{
    char word[100];

    if (n <= 1)
    {
        scanf("%s",word);
        printf("%s\n", word);
    }
    else
    {
        scanf("%s", word);
        reverseInputWords(n - 1);
        printf("%s\n", word);
    }
}
