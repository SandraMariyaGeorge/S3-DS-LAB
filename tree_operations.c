#include<stdio.h>
#define maxsize 20
void inserttree(int a[],int nvalue);
void deletetree(int a[],int nvalue);
void displaytree();
int root_val,i,a[50],lval,rval,nvalue,x,choice,op;
char ch;
int searchtree(int a[],int i,int key);
void main()
{
    //initialising the values to -1
    for(i=0;i<50;i++)
    {
        a[i]=-1;
    }
    do
    {
        i=1;
        printf("Enter your choice\n1--Insert\t2--Delete\t3--Display\n");
        scanf("%d",&choice);
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
    printf("Do you want to continue\t1--YES\t2--NO\n");
    scanf("%d",&op);
    }while(op==1);
}
void inserttree(int a[],int nvalue)
{
    i=searchtree(a,1,nvalue);
    if(i==0)
    {
        printf("Node Doesn't exist,Insertion not possible\n");
    }
    else
    {
        if(a[0]==-1)
        {
            printf("Enter the root node\n");
            scanf("%d",&root_val);
            a[0]=root_val;
        }
        else
        {
            printf("Do you want to create a left child or a right child(l/r)\n");
            fflush(stdin);
            scanf("%c",&ch);
            if(ch=='l'||ch=='L')
            {
                printf("Enter the left child value..\n");
                scanf("%d",&lval);
                if(a[2*i-1]==-1)
                {
                    a[2*i-1]=lval;
                }
                else
                {
                    printf("Insertion not possible\n");
                }
            }
            if(ch=='r'||ch=='R')
            {
                printf("Enter the right child value..\n");
                fflush(stdin);
                scanf("%d",&rval);
                if(a[2*i+1-1]==-1)
                {
                    a[2*i+1-1]=rval;
                }
                else
                {   
                    printf("Insertion not possible\n");
                }
            }
        }
    }
}
void deletetree(int a[],int nvalue)
{
    i=searchtree(a,1,nvalue);
    if(i==0)
    {
        printf("Node Doesn't exist,Deletion not possible\n");
    }
    else
    {
        if((a[2*i-1]==-1)&&a[2*i+1-1]==-1)
        {
            a[i-1]=-1;
        }
        else
        {
            printf("Deletion not possible,it has child nodes\n");
        }
    }
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
    if (a[i-1]==key)
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