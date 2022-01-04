#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          //could be any data type, or more fields
    struct node *link; // ONLY ONE LINK
};

int main(void)
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    head->data = 666;

    printf("Node Data: %d\n", head->data);
    return 0;
}
