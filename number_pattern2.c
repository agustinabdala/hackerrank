#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
      
    int i, j;
    int size = (2*n)-1;
    int count = 0;
    
    for (i=0 ; i < size ;i++)
    {
        for (j=0 ; j < size; j++)
        {
            if(j >= count && j < size - count)
            {
                printf("%d ", n - count);
            }
            else if (j >= size-count) {
                printf("%d ", n+(j-size)+1);
            }
            else {
            printf("%d ", n-j);
            }
        }
        printf("\n");
        if(i >= (n-1)){count--;}
        else {count++;}
    }
    
    return 0;
}

