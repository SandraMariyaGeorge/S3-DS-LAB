#include <stdio.h>
#include <string.h>
#include <math.h>

char postfix[100];
double stack[100];
int top = -1;

void push(double number) {
    top++;
    stack[top] = number;
}

double pop() {
    double del_element;
    del_element = stack[top];
    top--;
    return del_element;
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void main() {
    char operand;
    double x, y, result;
    printf("Enter the postfix expression: ");
    gets(postfix);
    postfix[strlen(postfix) - 1] = '\0';

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (is_operator(postfix[i])) {
            operand = postfix[i];
            y = pop();
            x = pop();
            if (operand == '+') {
                result = x + y;
            } else if (operand == '-') {
                result = x - y;
            } else if (operand == '*') {
                result = x * y;
            } else if (operand == '/') {
                result = x / y;
            } else if (operand == '^') {
                result = pow(x, y);
            }
            push(result);
        } else 
        {
            push((double)(postfix[i] - '0'));
        }
    }
    printf("The evaluated expression is: %f", pop());
}