#include <stdio.h>

int main(void)
{
    char string[100] = "shauncomino";
    int size = 100;
    int str_size = 0;
    for (int i = 0; i < size; ++i)
    {
        if (string[i] == '\0')
            str_size = i;
    }
    printf("Size of string is %d\n", str_size);
}
