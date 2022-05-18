//Shaun Comino
//Dr. Steinberg
//COP3223 Section 5
//Small Program 8
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[50];
	int age;
}record_t;

record_t * createarray(int maxsize);
record_t * insert(record_t *myarray, int *maxsize, int *currentsize);
void display(record_t *myarray, int currentsize);
record_t * doubleit(record_t *arr, int size); //problem 1
int removerecord(record_t *arr, int size, int maxsize, int index); //problem 2

int main(void)
{

	int maxsize;
	int bit_size;

	printf("Enter a size for the dynamic array: ");
	scanf("%d", &maxsize);


	record_t *myarray = createarray(maxsize);
	int currentsize = 0;


	int option = -1;

	while(option != 0)
    {
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option:");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize);
                break;

            case 2:
                printf("Display was selected...\n");
                display(myarray, currentsize);
                break;

            case 3:
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                int index;
                scanf("%d", &index);
                currentsize = removerecord(myarray, currentsize, maxsize, index);
                break;

            case 4:
                printf("Exiting...\n");
                option = 0;
				break;

            default:
                printf("Invalid Selection...\n");
                break;


        }

    }

	free(myarray);

	myarray = NULL;

	return 0;
}

record_t * createarray(int maxsize)
{
	return (record_t *) malloc(maxsize * sizeof(record_t));
}

record_t * insert(record_t *myarray, int *maxsize, int *currentsize)
{
	if(*maxsize == *currentsize)
	{
		printf("Array is full...Need to doubleit...\n");
		myarray = doubleit(myarray, *maxsize);
        *maxsize = *maxsize * 2;
	}

	// Collecting record input from user
    printf("Enter the last name: ");
	scanf("%s", myarray[*currentsize].name);

	printf("Enter an age: ");
	scanf("%d", &myarray[*currentsize].age);

	++*currentsize;

	return myarray;
}

void display(record_t *myarray, int currentsize)
{
	printf("---------------------------------\n");
	for(int x = 0; x < currentsize; ++x)
	{
	    // Displaying each record value, must be hardcoded for typedef struct
	    // Accesses the values with pointers
	    printf("myarray[%d].name = %s\n", x, (x + myarray)->name); //try it with myarray[x].name
		printf("myarray[%d].age = %d\n", x, (x + myarray)->age); //try it with myarray[x].age
	}

	printf("---------------------------------\n");
}

record_t *doubleit(record_t *arr, int maxsize)
{
    record_t * heap_ptr = createarray(maxsize * 2);
    int curr_elements = maxsize / sizeof(record_t);

    for (int i = 0; i < maxsize; ++i)
    {
        heap_ptr[i].age = arr[i].age;
        strcpy(heap_ptr[i].name, arr[i].name);
    }
    free(arr);
    return heap_ptr;
}

int removerecord(record_t *arr, int size, int maxsize, int index)
{
    if (index > (maxsize - 1) || index < 0)
    {
        printf("Index out of bounds!\n");
        return size;
    }

    if (size == 0)
    {
        printf("No elements in the array!\n");
        return size;
    }

    // This is how many records will be shifted (max_entries - given_index)
    int loop_times = maxsize - index;

    // Copies every entry to the right of index to the entry at (index - 1)
    for (int i = 0; i < loop_times; ++i)
    {
        // Handles string manipulation
        strcpy(arr[index + i].name, arr[index + (i + 1)].name);
        arr[index + i].age = arr[index + (i + 1)].age;
    }

    // The only way the compiler will have gotten to this return
    // statement is if the record was capable of being
    // removed
    return --size;
}
