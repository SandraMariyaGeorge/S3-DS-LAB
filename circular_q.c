#include<stdio.h>
#include<stdlib.h>
# define MAX_SIZE 3
int front=-1,rear=-1,item,ch,del_item,op,i,fpos,rear_pos;
int Q[MAX_SIZE];
void enqueue();
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
		case 1: enqueue();
					break;
		case 2 : dequeue();
					break;
		case 3 : Display();
					break;
		default: printf("INVALID CHOICE\n");
	}
	printf("\n");
	printf("DO YOU WANT TO CONTINUE\n");
	printf("1-YES\t\t2--NO\n");
	scanf("%d",&op);
	}while(op==1);
	
}
void enqueue()
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
		if(front==rear)//single element
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
void Display()
{
    fpos = front;
    rear_pos = rear;
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if( fpos <= rear_pos )
    {
        while(fpos <= rear_pos)
        {
            printf("Q[%d]=%d ",fpos,Q[fpos]);
            fpos++;
        }
    }
    else
    {
        while(fpos <= MAX_SIZE-1)
        {
            printf("Q[%d]=%d ",fpos,Q[fpos]);
            fpos=fpos+1;
        }
        fpos = 0;
        while(fpos <= rear_pos)
        {
            printf("Q[%d]=%d ",fpos,Q[fpos]);
            fpos++;
        }
    }
    printf("\n");
}
