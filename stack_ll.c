#include<stdio.h>
#include<stdlib.h>
void push(int item);
void pop();
void display();
struct node
{
	int data;
	struct node *link;
};
struct node *top,*new,*temp,*ptr;
int item,op,ch;
void push(int item)
{
	new=(struct node*)malloc (sizeof(struct node));
	new->data=item;
	new->link=NULL;
	if(top==NULL)
	{
		top=new;
		
	}
	else
	{
		new->link=top;
		top=new;
	}
}

void pop()
{
	if(top==NULL)
	{
		printf("The deletion not possible\n");
	}
	else
	{
		temp=top;
		printf("The deleted item is %d \n",temp->data);
		if(top->link==NULL)
		{
			top=NULL;
			free(temp);
		}
		else
		{
			top=temp->link;
			free(temp);
		}
	}
}
void display()
{
	ptr=top;
	printf("The elements in the stack \n");
	
	while(ptr->link!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
	printf("%d\t",ptr->data);
	printf("\n");

}
void main()
{
	do
	{
		printf("1--push\t\t2--pop\t\t3--display\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the item to be inserted \n");
					  scanf("%d",&item);
					  push(item);
					  break;
			case 2: pop();
				     break;
			case 3: display();
						break;
		}
		printf("1--YES\t\t2--NO\n");
		scanf("%d",&op);
		}while(op==1);
}