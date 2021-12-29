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
    int result = 1;
    while (n > 0)
    {
        result *= n;
        n--;
        factorial(n);
    }
    return result;
}