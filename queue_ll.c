#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
}*temp,*ptr,*new,*rear,*front;
int item,op,ch;
void enqueue(int item);
void dequeue();
void display();
void main()
{
	do{
	printf("1--enqueue\t2--dqueue\t3--Display\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the item\n");
					scanf("%d",&item);
					enqueue(item);
					break;
		case 2: dequeue();
					break;
		case 3: display();
					break;
	}
	printf("Do you want to continue\n");
	printf("1-YES\t\t2--NO\n");
	scanf("%d",&op);
	}while(op==1);
}
void enqueue(int item)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->link=NULL;
	if(front==NULL)
	{
		front=rear=new;
	}
	else
	{
		rear->link=new;
		rear=new;
	}
}
void dequeue()
{
	if(front==NULL)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		printf("The deleted item is %d\n",front->data);
		if(front==rear)
		{
			temp=front=rear=NULL;
			free(temp);
		}
		else
		{
			temp=front;
			front=front->link;
			free(temp);
		}
	}
}
void display()
{
	ptr=front;
	printf("The current elements in the queue is \n");
	while(ptr->link!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
	printf("%d",ptr->data);
	printf("\n");
	
}