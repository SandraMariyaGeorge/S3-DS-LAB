#include<stdio.h>
void heapsort(int a[],int n);
void swap(int *a,int *b);
void heapify(int *a,int index,int n);
int a[20],n,i;

void main()
{
		printf("Enter the no. of terms of the array\n");
		scanf("%d",&n);
		printf("Enter the elements\n");
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("The Entered array is: \n");
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		heapsort(a,n);
		printf("Sorted array is:\n");
      for(i=1;i<=n;i++)
      {
      	printf("%d\t",a[i]);
      }
      printf("\n");
}

void heapsort(int a[],int n)
{
	for(i=n/2;i>=1;i--)
	{
		heapify(a,n,i);
	}
	for(i=n;i>1;i--)
	{
		swap(&a[1],&a[i]);
		heapify(a,i,1);
	}
}

void heapify(int *a,int n,int i)
{
	int largest =i;
	int left=2*i;
	int right=2*i+1;
	if(left<=n && a[left]>a[largest])//left child larger than parent 
	{
		largest=left;
	}
	if(right<=n && a[right]>a[largest])//right child larger than parent 
	{
		largest=right;
	}
	if(largest!=i)//if largest has changed
	{
		swap(&a[largest],&a[i]);
		heapify(a,n,largest);
	}
}

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b; 
    *b=temp;
}