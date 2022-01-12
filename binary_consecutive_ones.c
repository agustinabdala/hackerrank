#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 1023;

    int bin_arr[1000];
    int i = 0;
    //decimal to binary
    while(n !=0 )
    {
        bin_arr[i] = n%2;
        //printf("%d", bin_arr[i]);
        i++;
        n /= 2; 
    }
    
    int sum = 0;
    int temp = 1;

    for (int j = 0; j <= i; j++)
        if (bin_arr[j] && bin_arr[j + 1])
            temp++;

        else if(temp > sum)
        {
            sum = temp;
            temp = 1;
        }

    printf("%d\n", sum);
    
    

    return 0;
}
