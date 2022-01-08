#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack_arr[MAX]; //define array globally to avoid passing the array every other operation/function
int top = -1;       // indicates stack is empty

//prototypes
void push(int data);
void print_stack(int *stack_arr);
void pop();
int isFull();
int isEmpty();
int peek_top();

int main(void)
{
    int choice, data;

    while (1)
    {
        system("clear");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print top Element\n");
        printf("4. Print all elements of stack\n");
        printf("5. Quit\n");
        printf("=================================\n");
        printf("Please enter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number to push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Last element is %d\n", peek_top());
            scanf("%d", &data);
            break;

        default:
            break;
        }
    }
    return 0;
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack_arr[top] = data;
    print_stack(stack_arr); //optional
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    top--;

    print_stack(stack_arr); //optional
}

void print_stack(int *stack_arr)
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }
    for (int i = 0; i <= top; i++)
        printf(" | %d | ", stack_arr[i]);
    printf("\n");
}

int peek_top()
{
    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    return stack_arr[top];
}

int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}