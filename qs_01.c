// Write an algorithm and program that displays all the elements X in a binary
// search tree such that k1<=x,x>=k2 where k1 and k2 are two values supplied

#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lptr, *rptr;
} *root, *new, *ptr, *parent;

void insertbst(int item);
void displayrange(struct node *ptr, int k1, int k2);
void inorder(struct node *ptr);
int main()
{
    int ch, val, k1, k2;
    do
    {
        printf("enter your choice\n1--insert\t2--display values within range\t3--Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter value\n");
            scanf("%d", &val);
            insertbst(val);
            break;
        case 2:
            printf("enter the values for k1 and k2\n");
            scanf("%d%d", &k1, &k2);
            displayrange(root, k1, k2);
            break;
        default:
            printf("invalid");
        }
    } while (ch != 3);
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
            else
                ptr = ptr->rptr;
        }
        if (parent->data > item)
            parent->lptr = new;
        else
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