#include<stdio.h>
void inserttree(int a[],int nvalue);
void deletetree(int a[],int nvalue);
void displaytree();
int root_val,i,a[50],lval,rval,nvalue,x,maxsize;
char choice,ch;
int searchtree(int a[],int i,int key);
void main()
{
    printf("Enter your choice\n1--Insert\t2--Delete\n");
    scanf("%d",&choice);
    //initialising the values to -1
    for(i=0;i<50;i++)
    {
        a[i]=-1;
    }
    switch(choice)
    {
        case 1:
        printf("Enter the node value to which we need to insert\n");
        scanf("%d",&nvalue);
        inserttree(a,nvalue);
        break;
        case 2:
        printf("Enter the node to be deleted\n");
        scanf("%d",&nvalue);
        deletetree(a,nvalue);
        break;
        case 3:displaytree();
        break;
        default:printf("Invalid choice\n");
    }
}
void inserttree(int a[],int nvalue)
{
    i=searchtree(a,i,nvalue);
    if (i=0)
    {
        printf("Node Doesn't exist,Insertion not possible\n");
    }
    else
    {
        printf("Do you want to create a left child or a right child(l/r)");
        scanf("%d",&ch);
        if(ch=='l')
        {
            printf("Enter the left child value..");
            scanf("%d",&lval);
        }
        if(ch=='r')
        {
            printf("");
            scanf("");   
        }
    }
}
void deletetree(int a[],int nvalue)
{

}
void displaytree()
{
    printf("The Array Representation of the tree is:\n");
    for(i=0;i<maxsize;i++)
    {
        if(a[i]!=-1)
            printf("a[%d]=%d ",i+1,a[i]);
        else
            printf("         ");
    }
    printf("\n");
}
int searchtree(int a[],int i,int key)
{
    if (a[i]==key)
        return i;
    else
    {
        if(2*i<=maxsize)
            x=searchtree(a,2*i,key);
        else
            return 0;
        if(x==0&&(2*i+1)<=maxsize)
            x=searchtree(a,2*i+1,key);
        return x;
    }
}