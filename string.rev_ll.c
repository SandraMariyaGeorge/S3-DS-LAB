#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data;
	struct node *prev,*next;
};
struct node *head=NULL,*tail=NULL,*new,*ptr;
char str[50];
int l,i;
void pushtoll(char item);
void main()
{
	printf("Enter the string :\n");
	gets(str);
	l=strlen(str);
	for(i=0;i<l;i++)
	{
		pushtoll(str[i]);
	}
	printf("The Reversed string is:\n");
	for(ptr=tail;ptr->prev!=NULL;ptr=ptr->prev)
	{
		printf("%c",ptr->data);
	}
	printf("%c\n",ptr->data);
}
void pushtoll(char item)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->prev=NULL;
	new->next=NULL;
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