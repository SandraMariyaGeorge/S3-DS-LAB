#include<stdio.h>
int binary_search(int *a,int low,int high,int ele)
{
    int mid;
    mid=(low+high)/2;
    if(low>high)
    {
        return -1;
    }
    else if(a[mid]==ele)
    {
        return mid;
    }
    else if (a[mid]<ele)
    {
        low=mid+1;
        binary_search(a,low,high,ele);
    }
    else
    {
        high=mid-1;
        binary_search(a,low,high,ele);
    }
}
void main()
{
    int a[50],n,low,high,ele,ret,i;
    printf("Enter the no. of elements : ");
    scanf("%d",&n);
    printf("Enter the array elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched :\n");
    scanf("%d",&ele);
    printf("The Entered Array is :");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    low=0;
    high=n-1;
    ret=binary_search(a,low,high,ele);
    if (ret==-1)
    {
        printf("Element NOT FOUND!!");
    }
    else
    {
        printf("Element found at index : %d\n",ret);
    }
}