//  There are two linked lists A and B containing the following data: 
//  A:3, 7,10,15,16,9,22,17,32
//  B:16, 2,9,13,37,38,10,1,28
//  Write a program to create:  
//  -A linked list C that contains only those elements that are common in linked list A and B. 
//  -A linked list D which contains all elements of A as well as B ensuring that there is no repetition of elements.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL,*new,*ptr,*ptr1,*ptr2;

int search(int val,struct node *ptr);
void insert(struct node *head,int val);
void makellC();
void makellD();
void display(struct node *head);

void main()
{
    int ch,val;
    do{
        printf("Enter your choice\n1--insert to A\t2--insert to B\t3--DISPLAY LL C(only common terms)\t4--DISPLAY LL(ll with no repetition)\t5--Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the value\n");
            scanf("%d",&val);
            insert(head1,val);
            break;
            case 2:printf("Enter the value\n");
            scanf("%d",&val);
            insert(head2,val);
            break;
            case 3:makellC();
            display(head3);
            break;
            case 4:makellD();
            display(head4);
            case 5:break;
        }
    }while(ch!=5);
}
void insert(struct node *head,int val)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->data=val;
	new->link=NULL;
    if(head==NULL)
	{
		head=new;
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
	}
    display(head);
}
void makellC()
{
    int s;
    ptr1=head1;
    while(ptr1!=NULL)
    {
        ptr2=head2;
        while(ptr2!=NULL)
        {
            if(ptr1->data==ptr2->data)
            {
                s=search(ptr1->data,head3);
                if(s!=0)
                    insert(head3,ptr1->data);
            }
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
}
void makellD()
{
    int s;
    ptr1=head1;
    while(ptr1!=NULL)
    {
        ptr2=head2;
        while(ptr2!=NULL)
        {
            if(ptr1->data==ptr2->data)
            {
                s=search(ptr1->data,head3);
                if(s!=0)
                    insert(head4,ptr1->data);
            }
            else
            {
                insert(head4,ptr1->data);
                insert(head4,ptr2->data);
            }
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
}

void display(struct node *head)
{
    if(head==NULL)
	{
		printf("THE LINKED LIST IS EMPTY\n");
	}
	else
	{
			ptr=head;
			while(ptr->link!=NULL)
			{
				printf("%d ",ptr->data);
				ptr=ptr->link;
			}
			printf("%d \n",ptr->data);
	}
}

int search(int val,struct node *ptr)
{
    while(ptr!=NULL)
    {
        if(ptr->data==val)
            return 0;
        ptr=ptr->link;
    }
    return -1;
}