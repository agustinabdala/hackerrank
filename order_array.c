#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;


void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    int p;
    int* area = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        p = (tr[i].a + tr[i].b + tr[i].c)/2;
        area[i] = (int)sqrt((p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c)));    
    }
    //order array area
    int min_idx; //move boundary of unsorted sub-array one at a time.
    for(int i= 0; i < (n-1); i++ )
        {
            min_idx = i; //find min item in sub-array
            for(int j = (i+1); j < n; j++)
            {
                if(area[j] < area[min_idx])
                    min_idx = j;
                    int temp = area[min_idx]; //swap found min with min_idx
                    area[min_idx] = area[i];
                    area[i] = temp; 
                    //swap simuntaneously all structure contents (a,b,c)
                    temp=tr[min_idx].a; //a
                    tr[min_idx].a=tr[i].a;
                    tr[i].a=temp;
                    temp=tr[min_idx].b; //b
                    tr[min_idx].b=tr[i].b;
                    tr[i].b=temp;
                    temp=tr[min_idx].c;  //c
                    tr[min_idx].c=tr[i].c;
                    tr[i].c=temp;
            }
        }
    /*for(int i= 0; i < n; i++)
        printf("%d %d %d %d\n", area[i], tr[i].a, tr[i].b, tr[i].c); */
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}