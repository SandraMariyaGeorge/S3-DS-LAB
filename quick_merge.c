#include<stdio.h>
#define max 20
void mergesort(int low,int high);
void merge(int low,int mid,int high);
void swap(int *a,int *b);
void quicksort(int l,int h);
int b[max],a[max];

void main()
{
    int ch;
    int op,n,i,l,h;
    do
    {
        printf("Enter the number of elements in the array\n");
        scanf("%d",&n);
        printf("Enter the elements into the array\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("1-Merge sort\t2-Quick sort\nEnter a choice\n");
        scanf("%d",&op);
        printf("The unsorted array is:\n");
        for(i=0;i<n;i++)
        {
             printf("%d\t",a[i]);
         }     
         printf("\n");
        switch(op)
        {
            case 1:  l=0;
                    h=n-1;
                    mergesort(l,h);
                    printf("Sorted array is:\n");
                     for(i=0;i<n;i++)
                    {
                        printf("%d\t",a[i]);
                    }
                    printf("\n");
                    break;
            case 2:l=0;
                 h=n-1;
                quicksort(l,h);
                printf("Sorted array is:\n");
                for(i=0;i<n;i++)
                {
                    printf("%d\t",a[i]);
                 }
                printf("\n");
        }
        printf("Do you want to continue?\n");
        scanf("%d",&ch);
     }while(ch!=0);
} 
void mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low,int mid,int high)
{
    int k,j,i;
    k=low;
    i=low;
    j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;

        }
        else
        {
            b[k]=a[j];
            j++;
            k++;

        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;

    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;

    }
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }

}
void quicksort(int low,int high)
{
    int pivot,i,j;
    if(low<high)
    {
        pivot=a[low];
        i=low;
        j=high;
        while(i<j)
        {
            while(a[i]<pivot)
            {
                i++;
            }
            while(a[j]>pivot)
            {
                j--;
            }
            if(i<j)
            {
               swap(&a[i],&a[j]);
            }
        }
        swap(&a[j],&pivot);
        quicksort(low,j-1);
        quicksort(j+1,high);
     }

 }
 void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b; 
    *b=temp;
}