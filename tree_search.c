#include<stdio.h>
#define MAXSIZE 50
int root_val,i,a[MAXSIZE],lval,rval,key,n,x;
char ch;
void buildtree(int a[],int i,int val);
int searchtree(int a[],int i,int key);
void main()
{
    //initialising the values to -1
    for(i=0;i<MAXSIZE;i++)
    {
        a[i]=-1;
    }
    printf("Enter the value to be inserted at the root node\n");
    scanf("%d",&root_val);
    buildtree(a,1,root_val);
    printf("The Array Representation of the tree is:\n");
    for(i=0;i<MAXSIZE;i++)
    {
        if(a[i]!=-1)
            printf("a[%d]=%d ",i+1,a[i]);
        else
            printf("         ");
    }
    printf("\n");
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    n=searchtree(a,1,key);
    if(n==0)
    {
        printf("KEY NOT FOUND!!\n");
    }
    else
    {
        printf("Key found at index %d\n",n+1);
    }
}
void buildtree(int a[],int i,int val)
{
    if(i==0)
    {
        return;
    }
    else
    {
        a[i-1]=val;
        printf("DO YOU NEED TO CREATE A LEFT CHILD?(Y/N)\n");
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y')
        {
            printf("Enter the value to be inserted to left child..\n");
            scanf("%d",&lval);
            buildtree(a,2*i,lval);
        }
        else
        {
            buildtree(a,0,0);
        }
        printf("DO YOU NEED TO CREATE A RIGHT CHILD?(Y/N)\n");
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='Y'||ch=='y')
        {
            printf("Enter the value to be inserted to right child..\n");
            scanf("%d",&rval);
            buildtree(a,2*i+1,rval);
        }
        else
        {
            buildtree(a,0,0);
        }
    }
}
int searchtree(int a[],int i,int key)
{
    if (a[i]==key)
        return i;
    else
    {
        if(2*i<=MAXSIZE)
            x=searchtree(a,2*i,key);
        else
            return 0;
        if(x==0&&(2*i+1)<=MAXSIZE)
            x=searchtree(a,2*i+1,key);
        return x;
    }
}