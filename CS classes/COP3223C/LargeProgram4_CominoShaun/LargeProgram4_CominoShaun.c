//Shaun Comino
//Dr. Steinberg
//COP3223 Section 5
//Large Program 4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int price;
    int sqft;
    int bathrooms;
    int bedrooms;
    int age;
} house_t;

void populate(house_t *house_array, int initial_elements);
int insert(house_t *house_array, int current_elements, int maxsize);
int remove_record(house_t *house_array, int index, int current_elements, int maxsize);
int search(house_t *house_array, int current_elements);
void display(house_t *house_array, int current_elements);
int demolish_price(house_t *house_array, int index, int current_elements);
int save(house_t *house_array, int current_elements);

int main (void)
{
    srand(1);
    // This makes the program un-dynamic
    int maxsize = 30;

    // Declaring struct array
    house_t house_array[maxsize];
    int initial_elements = 6;

    // Initializing array with 6 values
    populate(house_array, initial_elements);

    // This will change during runtime
    int current_elements = initial_elements;
    int index;

    printf("Welcome to UCF's Real Estate Database System!\n");
    int option = -1;

    do
    {
        printf("What would you like to do?\n");
        printf("1: Insert a house record\n");
        printf("2: Remove a house record\n");
        printf("3. Search for a house record\n");
        printf("4. Display all house records\n");
        printf("5. Estimate the cost to demolish the house\n");
        printf("6. Exit\n");
        scanf("%d", &option);

        // Executes based on user input selection
        switch (option)
        {
            case 1:
                printf("Insert house selected...\n");
                current_elements = insert(house_array, current_elements, maxsize);
                break;

            case 2:
                printf("Remove house selected...\n");
                printf("Select which house index to remove: ");
                scanf("%d", &index);
                current_elements = remove_record(house_array, index, current_elements, maxsize);
                break;

            case 3:
                printf("Search for house selected...\n");
                search(house_array, current_elements);
                break;

            case 4:
                printf("Display all house records selected...\n");
                display(house_array, current_elements);
                break;

            case 5:
                printf("Estimate demolition cost selected...\n");
                printf("This selection estimates the cost to demolish a selected house in the database\n");
                printf("Enter the index of the house to estimate: ");
                scanf("%d", &index);
                demolish_price(house_array, index, current_elements);
                break;

            case 6:
                printf("Exiting database...\n");
                printf("Writing to file...\n");
                save(house_array, current_elements);
                option = 7;
                break;

            default:
                printf("Invalid selection!\n");
                break;
        }
    }
    while (option != 7);


    return 0;
}

void populate(house_t *house_array, int initial_elements)
{
    // Generates random values for each element within the
    // structure.
    // Adds a common sense minimum to the range.
    // E.g. you wouldn't have 0 bedrooms or 10 bathrooms
    for (int i = 0; i < initial_elements; ++i)
    {
        house_array[i].price = (rand() % 150000) + 100000;
        house_array[i].sqft = (rand() % 4000) + 800;
        house_array[i].bathrooms = (rand() % 4) + 1;
        house_array[i].bedrooms = (rand() % 10) + 1;
        house_array[i].age = (rand() % 125) + 10;
    }
}

int insert(house_t *house_array, int current_elements, int maxsize)
{
    // Doubtful that 30 elements will be present
    // But just in case! (preventing memory leaks)
    if (current_elements == maxsize)
    {
        printf("There is not enough room in the database to store a new record!\n");
        return current_elements;
    }

    // Declaring all struct variables
    int price, sqft, bathrooms, bedrooms, age;

    // User input for each variable
    printf("Enter the price of the house ($): ");
    scanf("%d", &price);

    printf("Enter the size of the house (square footage): ");
    scanf("%d", &sqft);

    printf("Enter the amount of bathrooms in the house: ");
    scanf("%d", &bathrooms);

    printf("Enter the amount of bedrooms in the house: ");
    scanf("%d", &bedrooms);

    printf("Enter the age of the house (years): ");
    scanf("%d", &age);

    // Setting the new structure's variables to given values
    house_array[current_elements].price = price;
    house_array[current_elements].sqft = sqft;
    house_array[current_elements].bathrooms = bathrooms;
    house_array[current_elements].bedrooms = bedrooms;
    house_array[current_elements].age = age;

    printf("House record added successfully!\n");

    // Since an element was appended to the struct array,
    // there is now (current_elements + 1) elements
    return ++current_elements;
}

int remove_record(house_t *house_array, int index, int current_elements, int maxsize)
{
    int loop_amount = maxsize - index;
    for (int i = 0; i < loop_amount; ++i)
    {
        // Sets the value of every struct (index to the end)
        // to the value of the struct to it's right (aside from the struct at
        // index itself)
        house_array[index + i].price = house_array[index + (i + 1)].price;
        house_array[index + i].sqft = house_array[index + (i + 1)].sqft;
        house_array[index + i].bathrooms = house_array[index + (i + 1)].bathrooms;
        house_array[index + i].bedrooms = house_array[index + (i + 1)].bedrooms;
        house_array[index + i].age = house_array[index + (i + 1)].age;
        // This will result in the last struct being set to
        // garbage values, hence the --current_elements
    }

    return --current_elements;
}

int search(house_t *house_array, int current_elements)
{
    // This could have been any attribute of the struct
    // but I figured price would be the most unique
    int price;
    printf("Enter the house's price: ");
    scanf("%d", &price);
    printf("\n");

    // Checks to see if each record is equal to the desired one
    // if it is, display it. Otherwise, print that it wasn't found
    for (int i = 0; i < current_elements; ++i)
    {
        if (house_array[i].price == price)
        {
            printf("House record found!\n");
            printf("Here is the remaining information: \n");
            printf("--------------------------\n");
            printf("House %d price: $%d\n", i, house_array[i].price);
            printf("House %d size: %d square feet\n", i, house_array[i].sqft);
            printf("House %d bathrooms: %d\n", i, house_array[i].bathrooms);
            printf("House %d bedrooms: %d\n", i, house_array[i].bedrooms);
            printf("House %d age: %d years\n", i, house_array[i].age);
            printf("--------------------------\n");
            return 0;
        }
    }
    printf("Sorry, the database does not contain that house record!\n\n");
}

void display(house_t *house_array, int current_elements)
{
    // Simply displays every record in house_t house_array
    for (int i = 0; i < current_elements; ++i)
    {
        printf("--------------------------\n");
        printf("House %d price: $%d\n", i, house_array[i].price);
        printf("House %d size: %d square feet\n", i, house_array[i].sqft);
        printf("House %d bathrooms: %d\n", i, house_array[i].bathrooms);
        printf("House %d bedrooms: %d\n", i, house_array[i].bedrooms);
        printf("House %d age: %d years\n", i, house_array[i].age);
        printf("--------------------------\n");
    }
}

int demolish_price(house_t *house_array, int index, int current_elements)
{
    // Error input handling
    if (index > (current_elements - 1) || index < 0)
    {
        printf("Index out of bounds! Record does not exist!\n");
        return 1;
    }

    int sqft = house_array[index].sqft;

    // I actually googled this, and the real value is between
    // [$4, $15] per square foot
    // so $10 seems appropriate
    int demo_price = 10 * sqft;
    printf("According to it's square footage, the cost to demolish House %d would be $%d\n", index, demo_price);
    return 0;
}

int save(house_t *house_array, int current_elements)
{
    // Since this is the only function that will use
    // the file pointer, the file pointer is declared,
    // opened, written to, and closed within this
    // function
    char file_name[] = "output.txt";
    FILE *output = fopen(file_name, "w");
    for (int i = 0; i < current_elements; ++i)
    {
        // Very similar to display() function, with just one more argument
        fprintf(output, "--------------------------\n");
        fprintf(output, "House %d price: $%d\n", i, house_array[i].price);
        fprintf(output, "House %d size: %d square feet\n", i, house_array[i].sqft);
        fprintf(output, "House %d bathrooms: %d\n", i, house_array[i].bathrooms);
        fprintf(output, "House %d bedrooms: %d\n", i, house_array[i].bedrooms);
        fprintf(output, "House %d age: %d years\n", i, house_array[i].age);
        fprintf(output, "--------------------------\n");
    }
    fclose(output);

    return 0;
}
