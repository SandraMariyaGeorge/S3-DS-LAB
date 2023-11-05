#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head,*ptr,*new,*temp,*ptr1;
int item,pos;
void insert();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void display();
void main()
{
	int choice,ch;
	do
	{
		printf("Enter your choice :\n");
		printf("1--insertion at beginning\n2--insertion at end\n3--insertion at particular position\n4--deletion at beginning\n5--deletion at end\n6--deletion at particular position\n7--Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert_beg();
			break;
			case 2:insert_end();
			break;
			case 3:insert_pos();
			break;
			case 4:delete_beg();
			break;
			case 5:delete_end();
			break;
			case 6:delete_pos();
			break;
			case 7:display();
			break;
			default:printf("Invalid choice\n");
				
		}
		printf("Do you want to continue\n1--YES\t2--NO\n");
		scanf("%d",&ch);
	}while(ch==1);
}
void insert()
{
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element to be inserted\n");
	scanf("%d",&item);
	new->data=item;
	new->link=NULL;
}
void insert_beg()
{
	insert();
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		new->link=head;
		head=new;
	}
}
void insert_end()
{
	insert();
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
}
void insert_pos()
{
	int i;
	printf("Enter the position to be inserted\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		insert_beg();
	}
	else
	{
		insert();
		ptr=head;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
		new->link=ptr->link;
		ptr->link=new;
	}
}
void delete_beg()
{
	if(head==NULL)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		
		if(head->link==NULL)//single node
		{
			printf("The deleted item is %d \n ",head->data);
			head=NULL;
		}
		else
		{
			temp=head;
			printf("The deleted item is %d \n",temp->data);
			head=temp->link;
			free(temp);
		}
	}
}
void delete_end()
{
	if(head==NULL)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		if(head->link==NULL)//single node
		{
			printf("The deleted item is %d \n ",head->data);
			head=NULL;
		}
		else
		{
			ptr=head;
			while(ptr->link!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->link;
			}
			printf("The deleted item is %d \n ",ptr->data);
			ptr1->link=NULL;
			free(ptr);
		}
	}
}
void delete_pos()
{
	 printf("Enter the position at which element should be deleted :\n");
    scanf("%d",&pos);
    ptr = head;
    int i;
    if (pos == 1) 
    {
        printf("\nElement deleted is : %d\n", ptr->data);
        head = head->link; 
        ptr->link = NULL;
        free(ptr);
    }
    else 
    {
        for (i = 1; i < pos - 1; i++) 
        {
            ptr = ptr->link;
        }
        temp= ptr->link;
        ptr->link = ptr->link->link;
        printf("\nElement deleted is : %d\n", temp->data);
        temp->link = NULL;
        free(temp);
	}
}
void display()
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
