#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    int* tmp1;
    int* tmp2; 
    *tmp1 = *a + *b;
    *tmp2 = abs(*a - *b); 
    *a = *tmp1;
    *b = *tmp2;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
