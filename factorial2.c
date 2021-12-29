#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int factorial(int n);

int main()
{
    int n;
    printf("Ingrese el numero a aplicar factorial:\n");
    scanf("%d", &n);
    printf("%d\n", factorial(n));
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}