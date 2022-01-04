#include <stdio.h>
#include <stdlib.h>

//Prototypes:
struct node *addEnd(struct node *tail, int data);
struct node *addToEmpty(int data);
struct node *addBeginning(struct node *tail, int data);
void print(struct node *tail);

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

int main(void)
{
    struct node *tail = NULL;
    tail = addToEmpty(10);
    tail = addBeginning(tail, 22);
    tail = addEnd(tail, 50);
    print(tail);
    return 0;
}

struct node *addToEmpty(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node *addBeginning(struct node *tail, int data)
{
    struct node *newP = addToEmpty(data);
    if (tail == NULL)
    {
        return newP;
    }
    else
    {
        struct node *temp = tail->next;
        newP->prev = NULL;
        newP->data = data;
        newP->next = NULL;

        newP->next = temp;
        newP->prev = tail;
        temp->prev = newP;
        tail->next = newP;
        return tail;
    }
}

struct node *addEnd(struct node *tail, int data)
{
    struct node *newP = addToEmpty(data);
    if (tail == NULL)
    {
        return newP;
    }
    else
    {
        struct node *temp = tail->next;

        newP->next = temp;
        newP->prev = tail;
        temp->prev = newP;
        tail->next = newP;
        tail = newP;
        return tail;
    }
}

void print(struct node *tail)
{
    if (tail == NULL)
    {
        printf("No elements in the list");
    }
    else
    {
        struct node *temp = tail->next;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
    printf("\n");
}