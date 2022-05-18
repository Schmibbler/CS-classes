#include <stdio.h>
#include <stdlib.h>



int main (void)
{
    int** twoDarray = (int **) malloc (sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
        twoDarray[i] = (int*) malloc (sizeof(int) * 10);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            twoDarray[i][j] = rand() % 10;


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            printf("%d ", twoDarray[i][j]);
        printf("\n");
    }





    return 0;
}
