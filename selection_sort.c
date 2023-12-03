#include<stdio.h>
int i,j,temp,a[20],n,min,loc;
void selection_sort(int a[],int n);
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
    selection_sort(a,n);
    printf("The Sorted Array is :\n ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void selection_sort(int a[],int n)
{
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                loc=j;
            }
        }
        if(loc!=i)
        {
            temp=a[i];
            a[i]=a[loc];
            a[loc]=temp;
        }
    }
}