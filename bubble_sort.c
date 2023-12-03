#include<stdio.h>
int i,j,temp,a[20],n;
void bubble_sort(int a[],int n);
void main()
{
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the elements to array : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("The Entered Array is :\n ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    bubble_sort(a,n);

    printf("The Sorted Array is :\n ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bubble_sort(int a[],int n)
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}