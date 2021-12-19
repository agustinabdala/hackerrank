#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
     int c, i, ndigit[10];

    for (i = 0; i < 10; i++ ){
        ndigit[i] = 0;
    }
    while((c = getchar()) != EOF) {
        switch (c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            ndigit[c - '0']++;
            break;

            default:
            break;
        }
    }

    for (i = 0; i < 10; i++ ){
        printf("%d ",ndigit[i]);
    }
 
 
 
         
    return 0;
}

