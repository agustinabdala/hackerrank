#include <stdio.h>

struct point
{
    float y, x;
};
struct rectangle
{
    struct point upper_left, lower_right;
};

float area_rect(struct rectangle rect)
{
    float rect_lenght, rect_height;
    rect_lenght = rect.lower_right.x - rect.upper_left.x;
    rect_height = rect.upper_left.y - rect.lower_right.y;
    return rect_height * rect_lenght;
}

void main(void)
{
    struct rectangle rect;
    printf("Input Upper Left : Coord X = ");
    scanf("%f", &rect.upper_left.x);
    printf("Input Upper Left : Coord Y = ");
    scanf("%f", &rect.upper_left.y);
    printf("Input Lower Right : Coord X = ");
    scanf("%f", &rect.lower_right.x);
    printf("Input Lower Right : Coord Y = ");
    scanf("%f", &rect.lower_right.y);


    printf("Area of rectangle is %f\n", area_rect(rect));
}