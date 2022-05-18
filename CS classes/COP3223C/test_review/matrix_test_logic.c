#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayGrid(int ** picture, int limit);
int blobDetect(int ** picture, int x, int y, int limit);

int main (void)
{

    srand(time(NULL));


    int size = 10;

	int ** picture = (int **) malloc(size * sizeof(int *));

	for(int x = 0; x < size; ++x)
		picture[x] = (int *) malloc(size * sizeof(int));

    for(int r = 0; r < size; ++r)
    {

        for(int c = 0; c < size; ++c)
        {


            picture[r][c] = rand() % 2; //generate random number between 0 and 1


        }

    }

    printf("\n\n");


    int numblobs = 0;

    for(int r = 0; r < size; ++r)
        for(int c = 0; c < size; ++c)
        {
            printf("Seed value coordinate is at (%d, %d)\n", r, c);
            if(blobDetect(picture, r, c, size) > 0)
            {
                ++numblobs;
                printf("Blob found!\n");
                printf("Total blobs: %d\n\n", numblobs);
            }
        }

    printf("\n\nTotal Blobs Found: %d\n\n", numblobs);

    return 0;
}


int blobDetect(int ** picture, int x, int y, int limit)
{

    int total_ones = 0;
    printf("Current grid:\n\n");
    displayGrid(picture, limit);
    if (picture[x][y] == 0)
        return 0;
    else if (picture[x][y] == 1)
    {
        total_ones++;
        printf("The value at (%d, %d) is a 1!\n", x, y);
        printf("Setting value at (%d, %d) to 0...\n", x, y);
        picture[x][y] = 0;
    }


    // This just prints the test coordinates
    printf("Here are the test coordinates...\n");
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            int x_distance = -1 * (1 - i);
            int y_distance = -1 * (1 - j);

            int test_x_coord = x + x_distance;
            int test_y_coord = y + y_distance;

            printf("(%d, %d)", test_x_coord, test_y_coord);

        }
        printf("\n");
    }
    printf("\n\n");

    int next_x;
    int next_y;


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x_distance = -1 * (1 - i);
            int y_distance = -1 * (1 - j);

            int test_x_coord = x + x_distance;
            int test_y_coord = y + y_distance;

            if ((test_x_coord >= 0 && test_x_coord < limit) && (test_y_coord >= 0 && test_y_coord < limit))
            {
                if (picture[test_x_coord][test_y_coord] == 1)
                {

                    next_x = test_x_coord;
                    next_y = test_y_coord;
                    printf("The coordinate (%d, %d) is a 1!\n", next_x, next_y);
                    printf("Previous 1 location was (%d, %d), the next location is (%d, %d)\n", x, y, next_x, next_y);
                    total_ones += 1 + blobDetect(picture, next_x, next_y, limit);

                }
                else
                {
                    printf("The coordinate (%d, %d) is not a 1!\n", test_x_coord, test_y_coord);
                    continue;
                }

            }
            else
                continue;
        }
        printf("\n");

    }
    printf("\n");

    return total_ones;

}

void displayGrid(int ** picture, int limit)
{

    for (int i = 0; i < limit; i++)
    {
        if (i == 0)
        {
            printf("\t");
            printf("    ");
        }

        printf("%d  ", i);
    }

    printf("\n");
    for(int r = 0; r < limit; ++r)
    {
        printf("\n\t");
        for(int c = 0; c < limit; ++c)
        {
            if (c == 0)
            {
                printf("%d   ", r, c);
            }
            printf("%d  ", picture[r][c]);
        }

    }
    printf("\n\n");
}
