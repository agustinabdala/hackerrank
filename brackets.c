//This is my practice for NESO Academy, Video #300 - C programming and data structures course in Youtube.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1; // indicates stack is empty

//prototypes

void push(char);
char pop(void);
int isFull();
int isEmpty();
int peek_top();
int check_balanced(char *s);
int match_char(char a, char b);

int main(void)
{
    char expression[MAX];
    int balanced;
    printf("Input string to check if brackets match \n");
    fgets(expression, MAX, stdin);

    balanced = check_balanced(expression);
    if (balanced == 1)
        printf("The expression is valid\n");
    else
        printf("The expression is NOT valid\n");

    return 0;
}

int check_balanced(char *s)
{
    int i;
    char temp;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            push(s[i]);

        if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if (isEmpty())
            {
                printf("Right brackets are more than left brackets\n");
                return 0;
            }
            else
            {
                temp = pop();
                if (!match_char(temp, s[i]))
                {
                    printf("Brackets type mismatch\n");
                    return 0;
                }
            }
        }
    }
    if (isEmpty())
    {
        printf("The expression is balanced\n");
        return 1;
    }
    else
    {
        printf("Left brackets are more than right brackets\n");
        return 0;
    }
}

int match_char(char a, char b)
{
    if (a == '[' && b == ']')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}

void push(char c)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top] = c;
}

char pop(void)
{
    char c;
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    c = stack[top];
    top--;
    return c;
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