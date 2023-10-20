#include<stdio.h>
void main()
{
	int choice,a[50],i,n,opt,flag,pos,e;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The Entered Array is:\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]=%d\t",i,a[i]);
	}
	printf("\n");
	do
	{
		printf("Select your choice\n1- Insertion\n2-Deletion\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the element to be inserted and postion\n");
			scanf("%d%d",&e,&pos);
			for(i=n;i>pos;i--)
			{
				a[i]=a[i-1];
				
			}		
			a[pos]=e;
			n=n+1;
			printf("The INSERTED Array is:\n");
			for(i=0;i<n;i++)
			{
				printf("a[%d]=%d\t",i,a[i]);
			}
			printf("\n");
			break;
			case 2://DELETE
				printf("Enter the element to be deleted\n");
				scanf("%d",&e);
				flag=0;
				for(i=0;i<n;i++)
	   			{
					if(a[i]==e)
					{
						flag=1;
						pos=i;
						break;
					}
				}
				for(i=pos;i<n;i++)
				{
					a[i]=a[i+1];
					
				}
				n=n-1;
				if(flag==1)
				{
					printf("The DELETED Array is:\n");
					for(i=0;i<n;i++)
					{
						printf("a[%d]=%d\t",i,a[i]);
					}
					printf("\n");
				}
				else
				{
					printf("Element not found in the array\n");
				}
				break;
				
			default : printf("Invalid\n");
						break;
		}
		printf("Do you want to continue\n");
		scanf("%d",&opt);
	}while(opt==1);
}