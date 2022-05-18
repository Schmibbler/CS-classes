#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char ltr;
}my_record_t;


my_record_t * createArray(int maxsize);
int insert(my_record_t *myarray, int maxsize, int currentsize);
void display(my_record_t *myarray, int currentsize);

int main(void)
{

    int maxsize;


    printf("Enter a size for the dynamic array: \n");
    scanf("%d", &maxsize);

    my_record_t *myarray = createArray(maxsize);
    int currentsize = 0;

    printf("myarray is pointing at %p\n", myarray);

    for (int i = 0; i < maxsize; ++i)
        currentsize = insert(myarray, maxsize, currentsize);


    currentsize = insert(myarray, maxsize, currentsize);
    display(myarray, currentsize);

    free(myarray);

    myarray = NULL;




    return 0;
}


my_record_t * createArray(int maxsize)
{
    return (my_record_t*) malloc(maxsize * sizeof(my_record_t));
}

int insert(my_record_t *myarray, int maxsize, int currentsize)
{
    if (currentsize >= maxsize)
    {
        printf("Array is full, can't insert another element!\n");
        return currentsize;
    }

    printf("Enter an integer value: ");
    scanf("%d", &myarray[currentsize].id);

    printf("Enter an letter value: ");
    scanf(" %c", &myarray[currentsize].ltr);

    return ++currentsize;


}
void display(my_record_t *myarray, int currentsize)
{
    printf("'''''''''''''''''''''''''''''\n");
    for (int x = 0; x < currentsize; ++x)
    {
        printf("myarray[%d] = %d\n", x, myarray[x].id);
        printf("myarray[%c] = %c\n", x, myarray[x].ltr);
    }

    printf("'''''''''''''''''''''''''''''\n");
}

