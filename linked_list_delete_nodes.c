#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          //could be any data type, or more fields
    struct node *link; // ONLY ONE LINK
};

void count_nodes(struct node *head);
void del_last_node(struct node *head);

struct node *add_at_end(struct node *ptr, int value);

int main(void)
{
    struct node *head = (struct node *)malloc(sizeof(struct node)); //Head Node pointint to first node
    head->data = 111;
    head->link = NULL;

    struct node *ptr = head; //insert at the end - simple way
    ptr = add_at_end(ptr, 12);
    ptr = add_at_end(ptr, 34);
    ptr = head; // to place the pointer at the start of the linked list to traverse

    count_nodes(head);

    del_last_node(head);
    count_nodes(head);

    del_last_node(head);
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

struct node *add_at_end(struct node *ptr, int value)

{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}

void del_last_node(struct node *head)
{
    if (head == NULL)
    {
        printf("list already empty");
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = head;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);  // frees last node
        temp->link = NULL; // assigns NULL to last node.
    }
}