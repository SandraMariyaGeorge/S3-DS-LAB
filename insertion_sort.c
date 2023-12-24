#include<stdio.h>
void insertion_sort(int a[],int n);
int n,i,a[20],temp,j,k;
void main()
{
	printf("Enter the no. of terms of the array\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    insertion_sort(a,n);
}
void insertion_sort(int a[],int n)
{
	printf("The Entered array is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0&&a[j]>temp;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
		printf("Pass %d - ",i);
		for(k=0;k<n;k++)
		{
			printf("%d ",a[k]);
		}
		printf("\n");
	}
	printf("The sorted array is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}