#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    int elements = 5;

    int *array = (int *) malloc(elements * sizeof(int));

    printf("Populating array...\n");
    for (int i = 0; i < elements; i++)
        array[i] = rand() % 10;

    printf("Original array pointer: %p\n", array);

    printf("Displaying array...\n");
    for (int i = 0; i < elements; i++)
        printf("%d ", array[i]);
    printf("\n");

    printf("Making new heap twice the size...\n");

    int *dbl_array = (int *) malloc(2 * (elements * sizeof(int)));

    printf("Doubled array heap ptr: %p\n", dbl_array);

    printf("Copying old array into doubled array...\n");
    for (int i = 0; i < elements; i++)
        dbl_array[i] = array[i];

    printf("Freeing old array heap...\n");
    free(array);

    printf("Populating new values into doubled array...\n");

    for (int i = 0; i < elements; i++)
        dbl_array[elements + i] = rand() % 10;

    elements *= 2;


    printf("Displaying doubled array with new values...\n");
    for (int i = 0; i < elements; i++)
        printf("%d ", dbl_array[i]);
    printf("\n");

    printf("And finally, freeing doubled array...\n");
    free(dbl_array);


    return 0;
}





