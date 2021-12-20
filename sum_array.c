#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    int sum = 0;
    int *arr;

    scanf("%d", &n);

    arr = malloc(n * sizeof(*arr));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
        sum += arr[i];

    printf("%d", sum);

    return 0;
}
