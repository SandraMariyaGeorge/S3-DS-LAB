// Write an algorithm and program to count the number of nodes a linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head, *ptr, *ptr1, *new;
int item, ch;
void insert_end();
void display();
void insert();
void delete_end();
void countOfNodes();
void main()
{
    do
    {
        printf("Enter your choice\n1--Insert\t2--Delete\t3--Show count of nodes\t4--Display\t5--Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_end();
            break;
        case 2:
            delete_end();
            break;
        case 3:
            countOfNodes();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 5);
}
void insert()
{
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted\n");
    scanf("%d", &item);
    new->data = item;
    new->link = NULL;
}
void delete_end()
{
    if (head == NULL)
    {
        printf("Deletion not possible\n");
    }
    else
    {
        if (head->link == NULL) // single node
        {
            printf("The deleted item is %d \n ", head->data);
            head = NULL;
        }
        else
        {
            ptr = head;
            while (ptr->link != NULL)
            {
                ptr1 = ptr;
                ptr = ptr->link;
            }
            printf("The deleted item is %d \n ", ptr->data);
            ptr1->link = NULL;
            free(ptr);
        }
    }
}
void insert_end()
{
    insert();
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("THE LINKED LIST IS EMPTY\n");
    }
    else
    {
        printf("The Linked list is : ");
        ptr = head;
        while (ptr->link != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("%d \n", ptr->data);
    }
}
void countOfNodes()
{
    int count = 0;
    display();
    if (head == NULL)
    {
        printf("0 nodes\n");
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            count++;
            ptr = ptr->link;
        }
        printf("%d nodes\n", ++count);
    }
}