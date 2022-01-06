#include <stdio.h>

int main(void)
{
    int secs, h, m, s;

    printf("Input total seconds: \n");
    scanf("%d", &secs);

    h = (secs / 3600);
    m = (secs - (h * 3600)) / 60;
    s = (secs - (h * 3600) - (m * 60));

    printf("%d Seconds are equivalent to\nHours: %d, Minutes: %d, Seconds%d", secs, h, m, s);
    return 0;
}