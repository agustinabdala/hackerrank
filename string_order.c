#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10000

int main() {

    int n;
    int count = 0;
    
    scanf("%d", &n);
    char s[MAX];
    char even[MAX];    
    char odd[MAX];

while(count < n)
{
    scanf("%s", s);
    for(int i=0;i < strlen(s);i++){
        if(i%2 == 0){ //even
            printf("%c", s[i]);
        }
    }
    printf(" ");
    for(int i=0;i < strlen(s);i++){
        if(i%2 != 0){ //odd
            printf("%c", s[i]);   
        }
   
    }
    
    ++count;
    printf("\n");
}

    return 0;
}

