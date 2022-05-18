#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **populate(int rows, int columns);
void display(int rows, int columns, int **dyn_array);

int main (void)
{
    srand(time(NULL));
    int rows, columns;
    printf("Enter rows, columns\n");
    scanf("%d", &rows);
    scanf("%d", &columns);
    int **dyn_array = populate(rows, columns);

    display(rows, columns, dyn_array);

    for (int i = 0; i < rows; i++)
    {
        free(dyn_array[i]);
        dyn_array[i] = NULL;
    }
    free(dyn_array);
    dyn_array = NULL;

    return 0;
}

void display(int rows, int columns, int **dyn_array)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d ", dyn_array[i][j]);
        printf("\n");
    }
}

int **populate(int rows, int columns)
{
    int **dyn_array = (int **) malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
        dyn_array[i] = (int *) malloc(columns * sizeof(int));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            dyn_array[i][j] = rand() % 10;

    return dyn_array;

}



