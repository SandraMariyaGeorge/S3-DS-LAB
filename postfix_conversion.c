#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
void pf(char infix[MAX_SIZE]);
void push(char s);
char pop();
int precedance(char s);
int top=-1;
char stack[MAX_SIZE], infix[MAX_SIZE];
void main()
{
    char postfix[MAX_SIZE];
    printf("Enter the expression\n");
    gets(infix);
    pf(infix);
}
void pf(char infix[MAX_SIZE])
{
    int i,j=0;
    char next, symbol, postfix[MAX_SIZE];

    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':push(symbol);
                    break;
            case ')':while((next=pop())!='(')
                    {
                        postfix[j]=next;
                        j++;
                    }
                    break;
            case '^':while(precedance(stack[top])>precedance(symbol))
            {
                postfix[j]=pop();
                j++;
            }
            push(symbol);
            break;
            case '+':
            case '-':
            case '*':
            case '/':
           
            while(precedance(stack[top])>=precedance(symbol))
            {
                postfix[j]=pop();
                j++;
            }
            push(symbol);
            break;
            default:postfix[j]=symbol;
                    j++;
                    break;
        }
    }
    while(top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("The Postfix Expression is:\n");
    puts(postfix);
   
}

void push(char s)
{
    ++top;
    stack[top]=s;
}
char pop()
{
    char del_item;
    del_item=stack[top];
    top--;
    return del_item;
}
int precedance(char s)
{
    switch(s)
    {
        case '^':return 3;
                break;
        case '*':
        case '/':
                return 2;
                break;
        case '+':
        case '-':
                return 1;
                break;
        default:return 0;
                break;
    }
}
