#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(void)
{
    char s[MAX];
    int pal, i, j, size;
    printf("Input string to check if it's a palindrome\n");
    scanf("%s", s);
    size = (int)strlen(s);
    printf("String Length: %d\n", size);

    for (i = 0, j = size - 1; i < (size / 2); i++, j--)
    {
        if (s[i] != s[j])
        {
            pal = 0;
            break;
        }
        pal = 1;
    }
    pal == 1 ? printf("PALINDROME\n") : printf("NOT PALINDROME\n");
}