#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10000

int main() {

    int n;
    
    scanf("%d", &n);
    char s[n][MAX];

    for (int i = 0; i < n; i++)
        for(int j = 0; j <=MAX; j++){
            //scanf("%s", s[i][j]);
            scanf("%[^\n]%*c", s[i][j]); 

        }

    for (int i = 0; i < n; i++){
        //printf("%s", s);
        for(int j = 0; j<=MAX-1; j++){
            printf("%c", s[i][j]);
        }
    }
    
    return 0;
}
