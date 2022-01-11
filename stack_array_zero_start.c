#include <stdio.h>
#include <stdlib.h> //in order to use exit()

#define MAX 5

int stack_array[MAX];
int first = -1; // to follow the topmost element

//prototypes
int isEmpty(void);
int isFull(void);
void push(int data);
void peek(void);
void pop(void);
void print(void);

int main(void)
{
    push(3);
    push(10);
    push(100);
    push(100);
    print();
    pop();
    print();
    pop();

    print();
    peek();

    return 0;
}

void push(int data)
{
    int i;
    if (isFull())
        printf("Stack Overflow\n");
    else
    {
        first++;
        for (i = first; i > 0; i--)
            stack_array[i] = stack_array[i - 1];
        stack_array[0] = data;
    }
}

void pop(void)
{
    if (isEmpty())
        printf("Stack Underflow");
    else
    {
        int i, value;
        value = stack_array[0];
        for (i = 0; i < first; i++)
            stack_array[i] = stack_array[i + 1];
        first--;
    }
}

void print(void)
{
    int i;
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        for (i = 0; i <= first; i++)
            printf(" | %d | ", stack_array[i]);
        printf("\n");
    }
}

int isEmpty(void)
{
    if (first == -1)
        return 1;
    else
        return 0;
}

int isFull(void)
{
    if (first == MAX - 1)
        return 1;
    else
        return 0;
}

void peek(void)
{
    if (isEmpty())
    {
        printf("Stack Undeflow\n");
        exit(1);
    }
    else
        printf("Top element is || %d ||\n", stack_array[0]);
}
