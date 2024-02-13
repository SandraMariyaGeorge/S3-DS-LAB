#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head, *ptr, *ptr1, *head1, *new, *new1;
int item;
void reverse_ll(struct node *ptr);
void insert();
void main()
{
    int ch;
    do
    {
        printf("Enter 1-insert 2-reverse ll 3- exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            reverse_ll(head);
            break;
        case 3:
            break;
        default:
            printf("invalid");
        }
    } while (ch != 3);
}
void reverse_ll(struct node *ptr)
{
    head1 = NULL;
    ptr1 = NULL;
    while (ptr != NULL)
    {
        item = ptr->data;
        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = item;
        new1->link = NULL;
        if (head1 == NULL)
        {
            head1 = new1;
            ptr1 = new1;
        }
        else
        {
            new1->link = head1;
            head1 = new1;
        }
        ptr = ptr->link;
    }
    printf("Reversed ll is \n");
    ptr1 = head1;
    while (ptr1->link != NULL)
    {
        printf("%d\t", ptr1->data);
        ptr1 = ptr1->link;
    }
    printf("%d\n", ptr1->data);
}
void insert()
{
    int item;
    printf("enter the ele\n");
    scanf("%d", &item);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = item;
    new->link = NULL;
    if (head == NULL)
    {
        head = new;
        ptr = head;
    }
    else
    {
        ptr->link = new;
        ptr = ptr->link;
    }
    printf("ll is \n");
    ptr = head;
    while (ptr->link != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("%d\n", ptr->data);
}
