//find smllest element and largest element in an bst
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lptr, *rptr;
} *root, *new, *ptr, *parent, *ptr1, *ptr2;
void insertbst(int item);
void findSmallLarge(struct node *ptr);
void inorder(struct node *ptr);
int main()
{
    int ch, val;
    do
    {
        printf("\nEnter your choice\n1--Insert\t2--find small large\t3--Inorder\t4--Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &val);
            insertbst(val);
            break;
        case 2:
            findSmallLarge(root);
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
void findSmallLarge(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("NO Elements\n");
    }
    else
    {
        // finding largest
        ptr1 = ptr;
        while (ptr1 != NULL)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->rptr;
        }
        printf("THE LARGEST NODE IS %d \n", ptr2->data);

        // finding smallest
        ptr1 = ptr;
        while (ptr1 != NULL)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->lptr;
        }
        printf("THE SMALLEST NODE IS %d \n", ptr2->data);
    }
}
