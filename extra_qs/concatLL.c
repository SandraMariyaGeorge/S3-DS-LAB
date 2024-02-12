#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL,*new,*ptr,*ptr1,*ptr2,*temp1,*temp2;

int search(int val,struct node *ptr);
struct node* insert(struct node *head,int val);
void makellC();
void makellD();
void display(struct node *head);
void concat(struct node *ptr1,struct node *ptr2);

void main()
{
    int ch,val;
    do{
        printf("Enter your choice\n1--insert to A\t2--insert to B\t3--Concat\t4--Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the value\n");
            scanf("%d",&val);
            head1=insert(head1,val);
            display(head1);
            break;
            case 2:printf("Enter the value\n");
            scanf("%d",&val);
            head2=insert(head2,val);
            display(head2);
            break;
            case 3:concat(head1,head2);
            display(head1);
            break;
            case 4: break;
        }
    }while(ch!=4);
}

struct node* insert(struct node *head,int val)
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
    return head;
}
void concat(struct node *ptr1,struct node *ptr2)
{
    temp1=ptr1;
    temp2=ptr2;
    while(temp1->link!=NULL)
    {
        temp1=temp1->link;
    }
    while(temp2!=NULL)
    {
        temp1->link=temp2;
        temp1=temp2;
        temp2=temp2->link;
    }
    display(head1);
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