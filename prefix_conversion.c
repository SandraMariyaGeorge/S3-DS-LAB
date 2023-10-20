
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

char stack[size];
char prefix[size];
int top = -1;

void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void push(char character)
{
    top++;
    stack[top] = character; 
}

char pop()
{
    char del_element;
    del_element = stack[top];
    top--;
    return del_element;
}

int is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3; 
    }
    return 0;
}

void main()
{
    char infix[size];
    printf("Enter the infix expression:\n");
    fgets(infix, size - 1, stdin);

    infix[strlen(infix) - 1] = '\0';

    reverseString(infix);


    int i,j=0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        char symbol = infix[i];
        if (symbol == '(')
        {
            while (stack[top] != ')')
            {
                prefix[j]=pop();
                j++;
            }
            pop();
        }
        else if (symbol == ')')
        {
            push(symbol);
        }
        else if (is_operator(symbol))
        {
            while (top >= 0 && precedence(stack[top]) > precedence(symbol))
            {
                prefix[j]=pop();
                j++;
            }
            push(symbol);
        }
        else
        {
            prefix[j]=symbol;
            j++;
        }
    }

    while (top >= 0)
    {
        prefix[j]=pop();
        j++;
    }
    reverseString(prefix);
    printf("The prefix Expression is\n");
    puts(prefix);
}