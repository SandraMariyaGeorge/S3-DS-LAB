#include<stdio.h>
#include<stdlib.h>
# define MAX_SIZE 3
int front=-1,rear=-1,item,ch,del_item,op,i;
int Q[MAX_SIZE];
void enqueue(int item);
void dequeue();
void Display();
void main()
{
do{
    printf("Enter your choice\n");
	printf("1--enqueue\t\t2--dequeue\t\t3--Display\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the item to be inserted\n");
					scanf("%d",&item);
					enqueue(item);
					break;
		case 2 : dequeue();
					break;
		case 3 : Display();
					break;
		default: printf("INVALID CHOICE\n");
	}
	printf("DO YOU WANT TO CONTINUE\n");
	printf("1-YES\t\t2--NO\n");
	scanf("%d",&op);
	}while(op==1);
	
}
void enqueue(int item)
{
	if(rear==MAX_SIZE-1)
	{
		printf("QUEUE IS FULL\nInsertion not possible\n");
	}
	else
	{
		if(front==rear)
		{
			front=0;
		}
		rear=rear+1;
		Q[rear]=item;
		
	}
}

void dequeue()
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
			front=front+1;
		}
		
	}
}
void Display()
{
	printf("The current queue is:\n");
    if(front!=-1)
    {
        for(i=front;i<=rear;i++)
	    {
	    	printf("Q[%d]=%d\t",i,Q[i]);
	    }
	printf("\n");
    }
	else
    {
        printf("The Queue is Empty\n");
    }
}
