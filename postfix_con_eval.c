                    /*INFIX TO POSTFIX CONVERSION AND EVALUATION*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX_SIZE 100
void pf(char infix[MAX_SIZE]);
void push(char s);
char pop();
int precedence(char s);
void evalpost(char postfix[MAX_SIZE]);
char infix[MAX_SIZE];
int top=-1,i,stack[MAX_SIZE];
void main()
{
    printf("Enter the expression\nINFIX : ");
    gets(infix);
    pf(infix);
}
void pf(char infix[MAX_SIZE])
{
    int j=0;;
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
            case '+':
            case '-':
            case '*':
            case '/':while(precedence(stack[top])>=precedence(symbol))
                    {
                        postfix[j]=pop();
                        j++;
                    }
                    push(symbol);
                    break;
            case '^':while(precedence(stack[top])>precedence(symbol))
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
    printf("POSTFIX: ");
    puts(postfix);
    evalpost(postfix);
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
int precedence(char s)
{
    switch(s)
    {
        case '^':return 3;
        break;
        case '*':
        case '/':return 2;
        break;
        case '+':
        case '-':return 1;
        break;
        default:return 0;
        break;
    }
}
void evalpost(char postfix[MAX_SIZE])
{
    char op;
    int symbol,x,y,result,eval;
    for(i=0;i<strlen(postfix);i++)
    {
        symbol=postfix[i];
        if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
        {
            op = symbol;
            y = pop();
            x = pop();
            switch (op)
            {
                case '+':
                result = x + y;
                break;
                case '-':
                result = x - y;
                break;
                case '*':
                result = x * y;
                break;
                case '/':
                result = x / y;
                break;
                case '^':
                result = pow(x, y);
                break;
                default:
                printf("Error: Invalid operator\n");
            }
            push(result);
        }
        else
        {
            push(symbol-'0');
        }
    }
    eval = pop();
    printf("RESULT: %d", eval);
}
/*OUTPUT
INFIX : 4+2*2-4/2*2
POSTFIX : 422*+42/2*-
RESULT : 4
*/