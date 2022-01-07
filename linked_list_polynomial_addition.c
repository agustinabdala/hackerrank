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
struct node *addition(struct node *headpol1, struct node *headpol2);

int main(void)
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *result = NULL;

    head1 = create(head1);
    head2 = create(head2);

    print_count_nodes(head1);
    print_count_nodes(head2);
    result = addition(head1, head2);
    print_count_nodes(result);

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
    printf("======================================================================================\n");

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

struct node *addition(struct node *headpol1, struct node *headpol2)
{
    struct node *result = NULL;
    struct node *temp1 = headpol1;
    struct node *temp2 = headpol2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->ex == temp2->ex)
        {
            result = insert_sorted_polynomial(result, (temp1->co + temp2->co), temp1->ex);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else if (temp1->ex > temp2->ex)
        {
            result = insert_sorted_polynomial(result, temp1->co, temp1->ex);
            temp1 = temp1->link;
        }
        else if (temp1->ex < temp2->ex)
        {
            result = insert_sorted_polynomial(result, temp2->co, temp2->ex);
            temp2 = temp2->link;
        }
    }
    while (temp1 != NULL)
    {
        result = insert_sorted_polynomial(result, temp1->co, temp1->ex);
        temp1 = temp1->link;
    }
    while (temp2 != NULL)
    {
        result = insert_sorted_polynomial(result, temp2->co, temp2->ex);
        temp2 = temp2->link;
    }
    return result;
}