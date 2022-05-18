#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
int modulus(int num_to_mod, int mod_by);

int main(void)
{
    printf("Comparing two remainder arrays using the traditional modulus, and a homebrew modulus function:\n\n");

    int rand_array1[MAX];
    for (int i = 0; i < MAX; ++i)
        rand_array1[i] = rand();

    srand(time(NULL));

    int rand_array2[MAX];
    int reg_mod_array[MAX];
    int homebrew_mod_array[MAX];

    for (int i = 0; i < MAX; ++i)
    {
        rand_array2[i] = rand();
    }

    for (int i = 0; i < MAX; ++i)
    {
        reg_mod_array[i] = rand_array1[i] % rand_array2[i];
        homebrew_mod_array[i] = modulus(rand_array1[i], rand_array2[i]);
        printf("Regular: %d %% %d == %d\n", rand_array1[i], rand_array2[2], reg_mod_array[i]);
        printf("Homebrew: %d %% %d == %d\n\n", rand_array1[i], rand_array2[2], homebrew_mod_array[i]);
    }

    return 0;
}

int modulus(int num_to_mod, int mod_by)
{
    if (mod_by < 0)
        mod_by *= -1;
    if (num_to_mod < 0)
        num_to_mod *= -1;

    int curr_num = num_to_mod;

    while (curr_num >= 0)
    {
        curr_num -= mod_by;
    }
    curr_num += mod_by;
    return curr_num;
}
