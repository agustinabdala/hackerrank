#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          //could be any data type, or more fields
    struct node *link; // ONLY ONE LINK
};

void count_nodes(struct node *head);
void add_at_end(struct node *head, int value);

int main(void)
{
    struct node *head = (struct node *)malloc(sizeof(struct node)); //Head Node pointint to first node
    head->data = 111;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node)); //second node
    current->data = 222;
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node)); // third node
    current->data = 333;
    current->link = NULL;
    head->link->link = current; //Updates link of second node

    printf("Nodes Data: 1st %d , 2nd %d , 3rd %d \n", head->data, head->link->data, head->link->link->data);
    count_nodes(head);
    add_at_end(head, 444);
    count_nodes(head);

    return 0;
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

void add_at_end(struct node *head, int value)
{
    struct node *ptr, *temp = NULL;
    ptr = head;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}