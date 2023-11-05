#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head,*tail,*new,*ptr,*ptr1,*temp;
int item,pos,op,ch,i;

void insert()
{
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted\n");
	scanf("%d",&item);
	new->data=item;
	new->prev=NULL;
	new->next=NULL;
}
void insert_beg()
{
	insert();
	if(head==NULL)
	{
		head=tail=new;
	}
	else
	{
		head->prev=new;
		new->next=head;
		head=new;
	}
}
void insert_end()
{
	insert();
	if(head==NULL)
	{
		head=tail=new;
	}
	else
	{
		tail->next=new;
		new->prev=tail;
		tail=new;
	}
}
void insert_pos()
{
	
	printf("Enter the position to which item to be inserted\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		insert_beg();
	}
	else
	{
		ptr = head;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->next;
		}
		if(ptr->next!=NULL)
		{
			insert();
			new->next=ptr->next;
			new->prev=ptr;
			ptr->next->prev=new;
			ptr->next=new;
		}
		else
		{
			insert_end();
		}
		

	}
	
}
void del_beg()
{
	if(head==NULL)
	{
		printf("ERROR: The LL is empty...Deletion not possible\n");
	}
	else if (head==tail)
	{
		temp=head;
		head=tail=NULL;
		printf("The deleted item is %d\n",temp->data);
		free(temp);
	}
	else
	{
		temp=head;
		printf("The deleted item is %d\n",temp->data);
		head=temp->next;
		head->prev=NULL;
		free(temp);
	}
}

void del_end()
{
	if(head==NULL)
	{
		printf("The LL is empty--Deletion not possible\n");
	}
	else if (head==tail)
	{
		temp=head;
		head=tail=NULL;
		printf("The deleted item is %d\n",temp->data);
		free(temp);
	}
	else
	{
		temp=tail;
		tail=temp->prev;
		tail->next=NULL;
		printf("The deleted item is %d\n",temp->data);
		free(temp);
	}
}
void del_pos()
{
	printf("Enter the position of item to be deleted\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		del_beg();
	}
	else if (head==tail)
	{
		temp=head;
		head=tail=NULL;
		printf("The deleted item is %d\n",temp->data);
		free(temp);
	}
	else
	{
		ptr=head;
		for(i=0;i<pos-1;i++)
		{
			ptr=ptr->next;
		}
		temp=ptr;
		printf("The deleted item is %d \n",temp->data);
		ptr->prev->next=ptr->next;
		if(ptr->next!=NULL)
		{
			ptr->next->prev=ptr->prev;
		}
		else
		{
			temp=tail;
		    tail=temp->prev;
		    tail->next=NULL;
            free(temp);
		}
		free(temp);
	}
}
void display()
{
	if(head==NULL)
	{
		printf("The linked list is empty\n");
	}
	else
	{
		printf("The current LL is \n");
		ptr=head;
		while(ptr->next!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\t",ptr->data);
	}
	
}

void main()
{
	do{
	printf("1--Insert at beg\t2--Insert at end\t3--Insert at pos\n4--Deletion at beg\t5--Deletion at end\t6--Deletion from pos\n7--Exit\n");
	printf("Enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: insert_beg();
				display();
				break;
		case 2: insert_end();
				display();
				break;
		case 3: insert_pos();
				display();
				break;
		case 4: del_beg();
				display();
				break;
		case 5: del_end();
				display();
				break;
		case 6: del_pos();
				display();
				break;
		default:break;
	}
	printf("\n");
	}while(ch!=7);
}