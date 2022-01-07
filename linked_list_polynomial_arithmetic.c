#include <stdio.h>
#include <stdlib.h>

//polynomial equation input, order and display.
struct node
{
    float co;          //coefficient
    int ex;            //exponent
    struct node *link; // ONLY ONE LINK
};

void print_count_nodes(struct node *head);
struct node *insert_sorted_polynomial(struct node *head, float co, int ex);
struct node *create(struct node *head);

int main(void)
{
    struct node *head = NULL;

    head = create(head);
    print_count_nodes(head);
    return 0;
}

void print_count_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    printf("=======================================================================================\n");

    while (ptr != NULL)
    {
        count++;
        printf("%.2lf  x^%d", ptr->co, ptr->ex);
        ptr = ptr->link;
        if (ptr != NULL)
            printf(" + ");
        else
            printf("\n");
    }
    printf("=======================================================================================\n");
}

struct node *insert_sorted_polynomial(struct node *head, float co, int ex)
{
    struct node *temp;
    struct node *newP = (struct node *)malloc(sizeof(struct node));
    newP->co = co;
    newP->ex = ex;
    newP->link = NULL;

    if (head == NULL || newP->ex > head->ex)
    {
        newP->link = head;
        head = newP;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->ex > newP->ex)
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

struct node *create(struct node *head)
{
    int n, i;
    float coefficient;
    int exponent;

    printf("Enter the number of terms\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Provide coefficient for term %d: ", i + 1);
        scanf("%f", &coefficient);

        printf("Provide exponent for term %d: ", i + 1);
        scanf("%d", &exponent);
        head = insert_sorted_polynomial(head, coefficient, exponent);
    }
    return head;
}
