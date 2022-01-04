#include <stdio.h>
#include <stdlib.h>

//Prototypes:
struct node *addToEmpty(struct node *head, int data);
void count_nodes(struct node *head);
struct node *addBeginning(struct node *head, int data);
struct node *addEnd(struct node *head, int data);
struct node *addAfterPos(struct node *head, int data, int position);

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

int main(void)
{
    /*CREATION OF SINGLE NODE IN MAIN
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;  
    */
    struct node *head = NULL;
    head = addToEmpty(head, 10);
    count_nodes(head);

    head = addBeginning(head, 20);
    count_nodes(head);

    head = addEnd(head, 50);
    head = addEnd(head, 5050);

    count_nodes(head);

    head = addAfterPos(head, 666, 2);
    count_nodes(head);

    return 0;
}

struct node *addToEmpty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 10;
    temp->next = NULL;
    head = temp;

    return head;
}

void count_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        printf("Count: %d , Node Value: %d\n", count, ptr->data);
        ptr = ptr->next;
    }
    printf("Count= %d\n", count);
}

struct node *addBeginning(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->prev = NULL;
    //temp->next = head;
    //head->prev = temp;
    head = temp;
    return head;
}

struct node *addEnd(struct node *head, int data)
{
    struct node *temp, *tp;
    temp = malloc(sizeof(struct node));
    tp = head;

    temp->prev = NULL;
    temp->data = data;
    temp->prev = NULL;

    while (tp->next != NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;

    return head;
}

struct node *addAfterPos(struct node *head, int data, int position)
{
    struct node *newP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newP = addBeginning(newP, data);

    while (position != 1)
    {
        temp = temp->next;
        position--;
    }
    if (temp->next == NULL)
    {
        temp->next = newP;
        newP->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->prev = temp;
        newP->next = temp2;
    }
    return head;
}