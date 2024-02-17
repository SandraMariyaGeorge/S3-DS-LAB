// 31.Write a non recursive algorithm and program to find the inorder traversal of a
// binary tree.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lptr, *rptr;
} *root, *new, *ptr, *parent, *s[50];
int top = -1, c = 1;
void insertbst(int item);
void inorderNonRecursive(struct node *ptr);
void inorder(struct node *ptr);
struct node *pop();
void push(struct node *ptr);
int main()
{
    int ch, val;
    do
    {
        printf("\nEnter your choice\n1--Insert\t2--Inorder Non Recursive\t3--Inorder\t4--Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &val);
            insertbst(val);
            break;
        case 2:
            printf("The Inorder non recursive traversal is :\n");
            inorderNonRecursive(root);
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            break;
        default:
            printf("invalid");
        }
    } while (ch != 4);
}

void insertbst(int item)
{
    new = (struct node *)malloc(sizeof(struct node));
    new->data = item;
    new->rptr = new->lptr = NULL;
    if (root == NULL)
        root = new;
    else
    {
        ptr = root;
        while (ptr != NULL)
        {
            parent = ptr;
            if (ptr->data > item)
                ptr = ptr->lptr;
            else if (ptr->data < item)
                ptr = ptr->rptr;
            else
                break;
        }
        if (parent->data > item)
            parent->lptr = new;
        else if (parent->data < item)
            parent->rptr = new;
    }
    inorder(root);
    printf("\n");
}

void inorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    else
    {
        inorder(ptr->lptr);
        printf("%d ", ptr->data);
        inorder(ptr->rptr);
    }
}
void inorderNonRecursive(struct node *ptr)
{

    while (c != 0)
    {
        if (ptr != NULL)
        {
            push(ptr);
            ptr = ptr->lptr;
        }
        else
        {
            if (top != -1)
            {
                ptr = pop();
                printf("%d ", ptr->data);
                ptr = ptr->rptr;
            }
            else
                c = 0;
        }
    }
    printf("\n");
}

struct node *pop()
{
    struct node *ptr1;
    if (top >= 0)
    {
        ptr1 = s[top];
        top--;
        return ptr1;
    }
    return NULL;
}
void push(struct node *ptr)
{
    if (top == -1)
    {
        top++;
        s[top] = ptr;
    }
    else
    {
        top++;
        s[top] = ptr;
    }
}
