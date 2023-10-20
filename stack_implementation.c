#include<stdio.h>
#define MAX_SIZE 5
int stack[50],top=-1,item,i,choice,choicee,delitem;
void pop()
{
    if (top<0)
	{
		printf("Deletion is not possible\tStack Underflow\n");
	}
	else
	{
		printf("The deleted item is %d\n",stack[top]);
		top=top-1;
	}
}
void push()
{
	if (top>=MAX_SIZE-1)
	{
		printf("Insertion is not possible\tStack Overflow\n");
	}
	else
	{
		printf("Enter the element to be Inserted\n");
		scanf("%d",&item);
		top=top+1;
		stack[top]=item;
	}
}
void display()
{
	printf("The stack content is:\n");
	for(i=0;i<=top;i++)
	{
		printf("%d\t",stack[i]);
	}
	printf("\n");
}
void main()
{
	do
	{
		printf("Enter your choice\n1--Push\n2--Pop\n3--Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					push();
					break;
			case 2:pop();
					break;
			case 3:
					display();
					break;
			default:
					printf("Invalid choice\n");
					
		}
		printf("Do you want to continue?\n");
		scanf("%d",&choicee);
	}while(choicee==1);
}