#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
  int result = (a + b + c);
  if (n > 0)
  {
      a = b;
      b = c;
      c = result;
      n--;
      result += find_nth_term(n, a, b, c);
  }
  return result;

}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}