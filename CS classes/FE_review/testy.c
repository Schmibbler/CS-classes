#include <stdio.h>
#include <stdlib.h>

/// Functions for Matrices processing
typedef struct {
    double ** matrix;
    int rows;
    int cols;
} Matrix;

double ** element_wise_multiplication(double ** arr1, double ** arr2, int rows, int columns);
double ** allocate_array(double ** arr, int rows, int columns);
void rand_populate(Matrix * mat);
void display(Matrix * mat);
double randfrom(double min, double max);
double ** dot_product(double ** arr1, double ** arr2, int arr1_rows, int arr1_cols, int arr2_rows, int arr2_cols);
Matrix * alloc_matrix(int rows, int columns);w
void free_matrix(Matrix * matrix);

/// Functions for Neural Network Processing

typedef struct {
    Matrix * weights_matrix;
    Matrix * next_layer;
    int node_count;
}Layer;



int main (void)
{


    Matrix * m1 = alloc_matrix(4, 2);
    Matrix * m2 = alloc_matrix(2, 4);
    //rand_populate(m1);
    //rand_populate(m2);
    //display(m1);



    /*
    m1->rows = 5;
    m1->cols = 5;

    allocate_array(m1->matrix, m1->rows, m1->cols);
    rand_populate(m1->matrix, m1->rows, m1->cols);
    display(m1->matrix, m1->rows, m1->cols);
    */
    //free_matrix(m1);
    return 0;
}


// Allocates memory space for a matrix
Matrix * alloc_matrix(int rows, int columns)
{
    Matrix * new_matrix = (Matrix *) malloc(sizeof(Matrix) * 1);
    new_matrix->rows = rows;
    new_matrix->cols = columns;
    allocate_array(new_matrix->matrix, new_matrix->rows, new_matrix->cols);
    return new_matrix;
}

void free_matrix(Matrix * matrix)
{
    for (int r = 0; r < matrix->rows; ++r)
        free(matrix->matrix[r]);
    free(matrix->matrix);
    free(matrix);
}

// Displays the 2D array passed into it
void display(Matrix * mat)
{

    int rows = mat->rows;
    int columns = mat->cols;

    double num;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            num = mat->matrix[r][c];
            if (num < 0.0)
                printf("%.2lf ", num);
            else
                printf(" %.2lf ", num);
        }
        printf("\n");
    }
    printf("\n\n");
}



double ** allocate_array(double ** arr, int rows, int columns)
{
    arr = (double **) malloc (sizeof(double) * rows);

    for (int r = 0; r < rows; r++)
        arr[r] = (double *) malloc (sizeof(double) * columns);

    return arr;
}

void rand_populate(Matrix * mat)
{
    int rows = mat->rows;
    int columns = mat->cols;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < columns; c++)
            mat->matrix[r][c] = randfrom(-1.0, 1.0);
}

double randfrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

double ** dot_product(double ** arr1, double ** arr2, int arr1_rows, int arr1_cols, int arr2_rows, int arr2_cols)
{
    if (arr1_rows != arr2_cols)
    {
        printf("Dimension mismatch: %d vs %d\n", arr1_rows, arr2_cols);
        exit(69);
    }

    double ** result_arr = allocate_array(result_arr, arr1_rows, arr2_cols);

    for (int r = 0; r < arr1_rows; ++r)
        for (int c = 0; c < arr2_cols; ++c)
        {
            int index = 0;
            while (index < arr1_rows)
            {
                result_arr[r][c] += arr1[r][index] * arr2[index][c];
                index++;
            }

        }

    return result_arr;
}


