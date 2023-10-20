#include<stdio.h>
#include<stdlib.h>
# define MAX_SIZE 4
int front=-1,rear=-1,item,ch,del_item,op,i,temp;
int Q[MAX_SIZE];
void enqueuefront();
void enqueuerear();
void dequeuefront();
void dequeuerear();
void Display();
void main()
{
do{

	printf("1--enqueuerear\t\t2--enqueuefront\t\t3--dequeuefront\t\t4--dequeuerear\t\t5--Display\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: enqueuerear();
					break;
		case 2: enqueuefront();
					break;
		case 3: dequeuefront();
					break;
		case 4 : dequeuerear();
					break;
		case 5 : Display();
					break;
		default: printf("INVALID CHOICE\n");
	}
	printf("\n");
	printf("DO YOU WANT TO CONTINUE\n");
	printf("1-YES\t\t2--NO\n");
	scanf("%d",&op);
	}while(op==1);
	
}
void enqueuerear()
{
	printf("Enter the item to be inserted\n");
	scanf("%d",&item);
	if(front==(rear+1)%MAX_SIZE)
	{
		printf("QUEUE IS FULL\nInsertion not possible\n");
	}
	else
	{
		if(front==-1)
		{
			front=0;
			rear=0;
			Q[rear]=item;
		}
		else
		
		{
		rear=(rear+1)%MAX_SIZE;
		Q[rear]=item;
		}
		printf("%d is the entered item",Q[rear]);
	}
}

void dequeuefront()
{
	if(front==-1)
	{
		printf("QUEUE IS EMPTY\nDeletion not possible\n");
	}
	else
	{
		del_item=Q[front];
		printf("%d is the deleted item\n",del_item);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%MAX_SIZE;
		}
		
	}
}
void enqueuefront()
{
	printf("Enter the item to be inserted\n");
	scanf("%d",&item);
	if(front==-1)
	{
		front=0;
		Q[front]=item;
	}
	else
	{
		if(front==0)
        {
            temp=MAX_SIZE-1;
        }
        else
        {
            temp=front-1;
        }
		if(temp==rear)
		{
			printf("QUEUE IS FULL\n");
		}
	    else
		{
			front=temp;
			Q[front]=item;
		}
	}
		
}
void dequeuerear()
{
	if(rear==-1)
	{
		printf("QUEUE IS EMPTY\nDeletion not possible\n");
		
	}
	else
	{
		del_item=Q[rear];
		printf("%d is the deleted item",Q[rear]);
		if(rear==front)
		{
			rear=-1;
			front=-1;
		}
		else if(rear==0)
		{
			rear=MAX_SIZE-1;
		}
		else
		{
			rear=rear-1;
		}
	}
}
void Display()
{
	printf("The current queue is:\n");
	for(i=front;i!=(rear+1)%MAX_SIZE;i=(i+1)%MAX_SIZE)
	{
		printf("%d\t",Q[i]);
	}
	printf("\n");
}