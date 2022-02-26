//Name: Shaun Comino
//Dr. Steinberg
//COP3502 Spring 2022
//Programming Assignment 2

#include<stdio.h>
#include<stdlib.h>

int blobDetect(int ** picture, int x, int y, int limit);

int main()
{
	//setup randomness
    int x;

    printf("Enter seed: ");
    scanf("%d", &x);

    srand(x); //set seed

	printf("Enter the size of the picture: ");

	int size;
	scanf("%d", &size);

	int ** picture = (int **) malloc(size * sizeof(int *));

	for(int x = 0; x < size; ++x)
		picture[x] = (int *) malloc(size * sizeof(int));

	for(int test = 1; test <= 5; ++test)
	{
		printf("Test %d\n", test);

		for(int r = 0; r < size; ++r)
			for(int c = 0; c < size; ++c)
				picture[r][c] = rand() % 2; //generate random number between 0 and 1

        for (int r = 0; r < size; ++r)
        {
            printf("\t");
            for(int c = 0; c < size; ++c)
                printf("%d ", picture[r][c]);
            printf("\n");
        }


		int numblobs = 0;

		for(int r = 0; r < size; ++r)
			for(int c = 0; c < size; ++c)
				if(blobDetect(picture, r, c, size) > 0)
					++numblobs;

		printf("There are %d blob(s) in the picture.\n", numblobs);
	}

	//Super important! I don't think I can emphasize how important this is to do!
	for(int x = 0; x < size; ++x)
		free(picture[x]);

	free(picture);

	return 0;
}

int blobDetect(int ** picture, int x, int y, int limit)
{

    // Storing the amount of ones in a variable
    int total_ones = 0;

    // This is the base case
    // i.e. if picture[x][y] == 0
    // then return 0 because a 1 is not detected
    if (picture[x][y] == 0)
        return 0;
    else if (picture[x][y] == 1)
    {
        // If there is a 1, add it to the total
        total_ones++;
        // Set the value at picture[x][y] to 0 otherwise it will
        // loop forever and/or return x blobs where x is the
        // total 1 count in the picture
        picture[x][y] = 0;
    }

    // Declaring the next coordinates to pass to the function
    int next_x;
    int next_y;

    // The two for loops following work as such:
    //
    // It creates an implicit 3x3 grid around the passed x and y coordinate,
    // for example:
    /*
        x = 0;
        y = 0;

           j=0    j=1    j=2
     i=0 [-1,-1][-1, 0][-1, 1]
     i=1 [ 0,-1][ 0, 0][ 0, 1]
     i=2 [ 1,-1][ 1, 0][ 1, 1]

    */
    // If the current coordinate within the 3x3 implicit grid
    // is not out of bounds ( less than 0 or greater than "limit")
    // it checks to see if it's a one,
    // if it is, then it calls blobDetect() with the newly discovered
    // 1 coordinate.

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // This is some tricky math that
            // calculates the distance from the passed
            // x and y coordinates
            int x_distance = -1 * (1 - i);
            int y_distance = -1 * (1 - j);

            int test_x_coord = x + x_distance;
            int test_y_coord = y + y_distance;

            // Checking if it's out of bounds
            if ((test_x_coord >= 0 && test_x_coord < limit) && (test_y_coord >= 0 && test_y_coord < limit))
            {
                // The magic and integral conditional statement of the entire program
                if (picture[test_x_coord][test_y_coord] == 1)
                {
                    // These are passed into the recursive call
                    next_x = test_x_coord;
                    next_y = test_y_coord;

                    // Recursive call with detected coordinate equaling 1
                    total_ones += blobDetect(picture, next_x, next_y, limit);

                    // Putting the return statement here breaks the program,
                    // as there can be more than one nearby 1 within the 3x3 grid.
                    // IF there were a return statement here...
                    /*

                                        0  0  1  <- It would detect and recursively call with this 1's coordinates
                       But skip this -> 1  1  0
                                        0  0  1  <- and this
                                           ^
                                           The middle 1 being picture[test_x_coord][test_y_coord]'s value
                    */
                    // Hence the total 1 count being stored in a primitive integer variable

                }
                // In case picture[test_x][test_y] != 1
                else
                    continue;
            }
            // In case either test_x or test_y are out of bounds
            else
                continue;
        }
    }
    return total_ones;
}
