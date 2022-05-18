#include <stdio.h>
#include <string.h>

void NoSpace(char *s1);

int main (void)
{

    char string[10];
    fgets(string, 10, stdin);
    NoSpace(string);

    printf("%s", string);
    return 0;
}
void NoSpace(char *s1)
{
    int len = strlen(s1);
    printf("Length: %d\n", len);
    for (int i = 0; i < len; i++)
        if (s1[i] == ' ')
            s1[i] = '_';

}
