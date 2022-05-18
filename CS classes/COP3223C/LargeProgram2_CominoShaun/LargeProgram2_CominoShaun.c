#include<stdio.h>
#include<ctype.h>

//Shaun Comino
//Dr. Steinberg
//COP3223 Section 5
//Large Program 2

// Function prototypes
void Greeting();
void DisplayMenu(); //display food menu
void Purchase(double *balance); //user will make a purchase
void ViewAccount(double *balance); //display current account balance of user
void Transaction(double *balance, double price); //transaction with user account
void Reload(double *balance); //reload your account balance

int main(void)
{
    // This function is not repeated
    // so it's not in the do-while loop
    Greeting();

    // Initialize balance to 0
    double balance = 0;

    // Makes pointer with balance address
    double *balptr = &balance;
    char choice;

    // Do-while loop for repeated menu option selection
    // 'while' the user doesn't select 'E', which exits.
    do{

        printf("*********************************************************************\n");
        printf("Please select one of the following options.\n");
        printf("P: Make a Purchase at Knightstop\n");
        printf("V: View Knight's Account Summary\n");
        printf("B: Browse Inventory at Knightstop\n");
        printf("R: Reload Knight's Account\n");
        printf("E: Exit\n");
        printf("*********************************************************************\n");
        printf("Please select what you would like to do.\n");
        printf("Option Selected: ");

        // Gathers choice user input
        scanf(" %c", &choice);

        // Handles the exception that the user inputs
        // a lowercase letter.
        choice = toupper(choice);

        // Switch-case statement. A case for each selection
        switch(choice)
        {
            case 'P':
                printf("\nYou have selected the Purchase Option\n");
                printf("*********************************************************************\n");
                Purchase(balptr);
                break;
            case 'V':
                printf("\nYou selected View Account Summary option.\n");
                ViewAccount(balptr);
                break;
            case 'B':
                printf("\nYou selected Browse Option\n");
                DisplayMenu();
                break;
            case 'R':
                printf("\nYou have selected the Reload Knight's Account Option.\n");
                Reload(balptr);
                break;
            case 'E':
                printf("\nYou are now exiting the application!\n");
                printf("You have $%.2f in your account.\n", *balptr);
                printf("Have a great day!\n");
                printf("Go Knights! Charge On!\n");
                printf("*********************************************************************\n");
                break;
            default:
                printf("\nInvalid Selection\n\n");
                break;
        }

    }while(choice != 'E');

    return 0;
}

// Greets the user
void Greeting()
{
    printf("*********************************************************************\n");
    printf("Welcome to UCF's Knight's Account Services!\n");
    printf("This is where you will manage your Knight's Account for all your purchasing needs at UCF!\n");
    printf("How can we help you today?\n");
    printf("*********************************************************************\n");
}

// Displays food menu
void DisplayMenu()
{
    printf("*********************************************************************\n");
    printf("Here is what we have in stock today!\n");
    printf("1. Bottled Water                 $1.00\n");
    printf("2. Chips                         $2.13\n");
    printf("3. Soda                          $1.12\n");
    printf("4. Wrap                          $5.31\n");
    printf("5. Candy Bag                     $3.21\n");
    printf("6. Cheese Pizza                  $6.24\n");
    printf("7. Chocolate Brownie             $1.23\n");
    printf("8. Chocolate Chip Cookie         $1.15\n");
    printf("*********************************************************************\n");
}

// Purchases an item
void Purchase(double *balptr)
{
    // Initializing all the menu item prices.
    double water = 1.00;
    double chips = 2.13;
    double soda = 1.12;
    double wrap = 5.31;
    double candy = 3.21;
    double pizza = 6.24;
    double brownie = 1.23;
    double cookie = 1.15;

    // Initializing user choice
    int choice;

    // Displays food menu
    DisplayMenu();
    printf("What would you like today?\n");
    printf("Option Selected: ");
    scanf("%d", &choice);
    printf("\n");

    // Switch-case statement. One case statement for each menu item.
    switch(choice)
    {
        case 1:
            printf("Bottled Water has been selected. Total cost is: $%.2f\n", water);
            printf("Beginning Transaction process.\n");
            Transaction(balptr, water);
            break;
        case 2:
            printf("Chips have been selected. Total cost is: $%.2f\n", chips);
            printf("Beginning Transaction process.\n");
            Transaction(balptr, chips);
            break;
        case 3:
            printf("Soda has been selected. Total cost is: $%.2f\n", soda);
            printf("Beginning Transaction process.\n");
            Transaction(balptr, soda);
            break;
        case 4:
            printf("Wrap has been selected. Total cost is: $%.2f\n", wrap);
            printf("Beginning Transaction process.\n");
            Transaction(balptr, wrap);
            break;
        case 5:
            printf("Candy Bag has been selected. Total cost is: $%.2f\n", candy);
            printf("Beginning Transaction process.\n");
            Transaction(balptr, candy);
            break;
        case 6:
            printf("Cheese Pizza has been selected. Total cost is: $%.2f\n", pizza);
            printf("Beginning Transaction process.\n");
            Transaction(balptr, pizza);
            break;
        case 7:
            printf("Chocolate Brownie has been selected. Total cost is: $%.2f\n", brownie);
            printf("Beginning Transaction process.\n");
            Transaction(balptr, brownie);
            break;
        case 8:
            printf("Chocolate Chip Cookie has been selected. Total cost is: $%.2f\n", cookie);
            printf("Beginning Transaction process.\n");
            Transaction(balptr, cookie);
            break;
        default:
            printf("Invalid Selection\n\n");
            break;
    }
}

void Transaction(double *balptr, double price)
{
    // Checks to see if there are sufficient funds
    // to make the purchase
    if (*balptr < price)
    {
        printf("You do not have enough in your account.\n");
        printf("Please reload your account balance\n");

        // Prompts user to reload balance
        // because funds are insufficient
        Reload(balptr);

        /*
        Recursively calls Transaction() because
        the user could have selected a reload amount
        that still ends up being less than the
        price. I.e $1.00
        */
        Transaction(balptr, price);
    }
    else
    {
        printf("Your account balance before official transaction: $%.2f\n", *balptr);
        printf("Billing $%.2f to your account.\n", price);

        // Here's where the magic happens.
        // Subtracts the food item price from balance.
        *balptr = *balptr - price;

        printf("Transaction was successful!\n");
        printf("You now have $%.2f in your account balance.\n", *balptr);
        printf("*********************************************************************\n");
    }
}

// Reloads balance when necessary or prompted
void Reload(double *balptr)
{
    int choice;
    printf("*********************************************************************\n");
    printf("1: $1.00\n");
    printf("2: $5.00\n");
    printf("3: $10.00\n");
    printf("Option Selected: ");
    scanf("%d", &choice);

    /*
    Select how much to reload.
    I'm hardcoding the values added
    to the balance because
    there are only 3 options
    */
    switch(choice)
    {
        case 1:
            *balptr = *balptr + 1.00;
            printf("*********************************************************************\n");
            printf("$1.00 has been added to your Knight's Account successfully!\n");
            printf("*********************************************************************\n");
            break;
        case 2:
            *balptr = *balptr + 5.00;
            printf("*********************************************************************\n");
            printf("$5.00 has been added to your Knight's Account successfully!\n");
            printf("*********************************************************************\n");
            break;
        case 3:
            *balptr = *balptr + 10.00;
            printf("*********************************************************************\n");
            printf("$10.00 has been added to your Knight's Account successfully!\n");
            printf("*********************************************************************\n");
            break;
        default:
            // Handles exception where user inputs
            // something other than 1, 2, or 3
            printf("Invalid Selection\n");
            break;
    }
}

// Views account balance
void ViewAccount(double *balptr)
{
    // Simple enough, prints the balance using a pointer
    printf("*********************************************************************\n");
    printf("Here is your current Knight's Account balance. \n");
    printf("You have $%.2f in your account\n", *balptr);
    printf("*********************************************************************\n");
}
