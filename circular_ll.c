#include<stdio.h>
#include<stdlib.h>
int i;

void insbeg();
void insend();
void inspos();
void delbeg();
void delend();
void delpos();
void display();

struct node
{
	int data;
	struct node *link;
};
struct node *ptr,*head=NULL,*ptr1,*temp,*new;

void main()
{
	int ch;
	do
	{  
		printf("1: Insertion at the beginning\n2: Insertion at the end\n3: Insertion at a particular position\n4: Deletion at the beginning \n5: Deletion at the end\n6: Deletion at a particular position\n7: Display\n8: Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:insbeg();
		 break;
		case 2:insend();
		 break;
		case 3:inspos();
		 break;
		case 4:delbeg();
		 break;
		case 5:delend();
		 break;
		case 6:delpos();
		 break;
		case 7:display();
		 break;
		case 8:
		 break;
		default: printf("Invalid Option\n");
		 break;
		}
	}while(ch!=8);
}


void insbeg()
{
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the item:");
	scanf("%d",&item);
	new->data=item;
	new->link=NULL;
	if(head==NULL)
	{
		head = new;
		head->link=head;
	}
	else
	{
		ptr=head;
        	while(ptr->link!=head)
        	{
           		ptr=ptr->link;
        	}
        	ptr->link=new;
        	new->link=head;
        	head=new;
	}
}
void insend()
{
	int item;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the item:");
	scanf("%d",&item);
	new->data=item;
	new->link=NULL;
	if(head==NULL)
	{
		head=new;
		head->link=head;
	}
	else
	{
		ptr=head;
		while(ptr->link!=head)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
        	new->link=head;
	}
}
void inspos()
{
	int item,pos;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the item:");
	scanf("%d",&item);
	new->data=item;
	new->link=NULL;
	printf("Enter the position:");
	scanf("%d",&pos);
	ptr=head;
	if(pos==1)
	{
		insbeg();
	}
	for(i=1;i<pos-1;i++)
	{
		ptr=ptr->link;
	}
	new->link=ptr->link;
	ptr->link=new;
}
void delbeg()
{
	if(head==NULL)
	{
		printf("Deletion not possible Linked List is Empty\n");
	}
	else if(head->link==head)
	{
		temp=head;
        	printf("del item is %d\n",temp->data);
        	head=NULL;
        	free(temp);
	}
	
	else
	{
		temp=head;
        	printf("del item is %d\n",temp->data);
        	ptr=head;
       	while(ptr->link!=head)
        	{
            	ptr=ptr->link;
        	}
		ptr->link=head->link;
		head=head->link;
      	free(temp);
	}
}
void delend()
{
	if(head==NULL)
	{
		printf("Deletion not possible as Linked List is Empty\n");
	}
	else if(head->link==head)
	{
		temp=head;
		printf("The deleted element is: %d\n",temp->data);
		head=NULL;
	}
	else
	{
		ptr=head;
	  	while(ptr->link!=head)
        	{
            	ptr1=ptr;
            	ptr=ptr->link;
        	}
        temp=ptr;
        printf("del item is %d\n",temp->data);
        ptr1->link=head;
        free(temp);
	}
}
void delpos()
{
	int pos;
	printf("Enter the position:");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("Deletion not possible as Linked List is Empty\n");
	}
	else if(pos==1)
	{
		delbeg();
	}
	else
	{
		ptr=head;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
		temp=ptr->link;
		printf("The deleted element is: %d\n",temp->data);
		ptr->link=temp->link;
		free(temp);
	}
}


void display()
{
	ptr=head;
	while(ptr->link!=head)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("%d\n",ptr->data);
}