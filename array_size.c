#include <stdio.h>

int main(void)
{
   int array[10][20] = {2,1,3,4,24,6,7,6,9};

   int array_size = sizeof(array)/sizeof(array[0][0]);
   printf("%d", array_size);
}