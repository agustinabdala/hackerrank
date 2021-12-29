#include <stdio.h>

struct point
{
    int y, x;
};
struct rectangle
{
    struct point upper_left, lower_right;
};

void print_area_rect(int ulx, int uly, int lrx, int lry)
{
    float rect_lenght, rect_height;
    struct rectangle rect;
    rect.upper_left.x = ulx;
    rect.upper_left.y = uly;
    rect.lower_right.x = lrx;
    rect.lower_right.y = lry;
    rect_lenght = rect.lower_right.x - rect.upper_left.x;
    rect_height = rect.upper_left.y - rect.lower_right.y;
    printf("Area: %f\n", rect_height * rect_lenght);
}

void main(void)
{
    print_area_rect(3,8,14,2);
}