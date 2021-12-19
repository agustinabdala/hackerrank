#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    int result;
    scanf("%d", &n);
    
    while(n>=9)
    {
        result += n%10;
        n /= 10;

    }
    printf("%d", n + result);
    
    //Complete the code to calculate the sum of the five digits on n.
    return 0;
}
