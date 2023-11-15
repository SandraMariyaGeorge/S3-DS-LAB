#include<stdio.h>
#include<stdlib.h>
struct node* readlist(int item);
void display(struct node *head);
struct node
{
	int data;
	struct node *prev,*next;
};
int i,n,e,a,item;
struct node *head=NULL,*tail=NULL,*new,*ptr,*temp;
struct node* readlist(int item);
void main()
{
	printf("Enter the no. of terms in the list\n");
	scanf("%d",&n);
	printf("Enter the elements to the list\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		head=readlist(a);
	}
	printf("Original list:\t");
 	display(head);
    printf("Enter the element to be deleted\n");
    scanf("%d",&e);
    if(head->data==e)
    {
        printf("Element is already in the front\n");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            while(ptr->data!=e)
            {
                ptr=ptr->next;
            }
            temp=ptr;
            ptr->prev->next=ptr->next;
            if(ptr->next!=NULL)
            {
                ptr->next->prev=ptr->prev;    
            }
            temp->prev=temp->next=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
            printf("The Modified list is :\t");
            display(head);
        }

    }
}
struct node* readlist(int item)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->next=NULL;
	new->prev=NULL;
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
	return head;
}
void display(struct node *head)
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }  
    printf("\n");
}