#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          //could be any data type, or more fields
    struct node *link; // ONLY ONE LINK
};

void count_nodes(struct node *head);
struct node *add_at_beginning(struct node *head, int value);
void add_at_beginning_pointer(struct node **head, int value);
struct node *reverse_linked_list(struct node *head);

struct node *add_at_end(struct node *ptr, int value);

int main(void)
{
    struct node *head = (struct node *)malloc(sizeof(struct node)); //Head Node pointint to first node
    head->data = 111;
    head->link = NULL;

    struct node *ptr = head; //insert at the end - simple way
    ptr = add_at_end(ptr, 22);
    ptr = add_at_end(ptr, 333);
    ptr = head; // to place the pointer at the start of the linked list to traverse

    count_nodes(head);

    head = reverse_linked_list(head);

    count_nodes(head);

    return 0;
}

struct node *add_at_beginning(struct node *head, int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    return head;
}

void add_at_beginning_pointer(struct node **head, int value) // adds a node at the beginning but w/o head = add_at_beginning(), just add_at...
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->link = NULL;

    ptr->link = *head;
    *head = ptr;
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
        ptr = ptr->link;
    }
    printf("Count= %d\n", count);
}

struct node *add_at_end(struct node *ptr, int value)
{
    struct node *prev = (struct node *)malloc(sizeof(struct node));
    prev->data = value;
    prev->link = NULL;
    ptr->link = prev;
    return prev;
}

struct node *reverse_linked_list(struct node *head)
{
    struct node *prev, *next = NULL;

    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
}