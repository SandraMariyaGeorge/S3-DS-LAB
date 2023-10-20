#include<stdio.h>
void transpose(int A[20][20])
{
    int B[20][20],m,n,t,q=1;
    m=A[0][0],n=A[0][1],t=A[0][2];
    B[0][0]=n,B[0][1]=m,B[0][2]=t;
    for(int c=0; c<=n-1; c++)
    {
        for(int p=1; p<=t; p++)
        {
            if(A[p][1]==c)
            {
                B[q][0]=A[p][1];
                B[q][1]=A[p][0];
                B[q][2]=A[p][2];
                q++;
            }
        }
    }
    printf("transpose\n");
    for(int i=0; i<=t; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
}

void addition(int A[20][20],int B[20][20])
{
    int c[20][20],k1,k2,k3;
    if(A[0][0]!=B[0][0]||A[0][1]!=B[0][1])
        printf("ADDITION NOT POSSIBLE");
    else
    {
        int t1=A[0][2],t2=B[0][2];
        k1=1,k2=1,k3=1;
        while(k1<=t1 && k2<=t2)
        {
            if(A[k1][0]<B[k2][0])
            {
                c[k3][0]=A[k1][0];
                c[k3][1]=A[k1][1];
                c[k3][2]=A[k1][2];
                k3++,k1++;
            }
            else if(A[k1][0]>B[k2][0])
            {
                c[k3][0]=B[k2][0];
                c[k3][1]=B[k2][1];
                c[k3][2]=B[k2][2];
                k3++,k2++;
            }


            else if(A[k1][1]<B[k2][1])
            {
                c[k3][0]=A[k1][0];
                c[k3][1]=A[k1][1];
                c[k3][2]=A[k1][2];
                k3++,k1++;
            }
            else if(A[k1][1]>B[k2][1])
            {
                c[k3][0]=B[k2][0];
                c[k3][1]=B[k2][1];
                c[k3][2]=B[k2][2];
                k3++,k2++;
            }
            else
            {
                c[k3][0]=A[k1][0];
                c[k3][1]=A[k1][1];
                c[k3][2]=A[k1][2]+B[k2][2];
                k3++,k1++,k2++;
            }

        }
        while(k1<=t1)
        {
            c[k3][0]=A[k1][0];
            c[k3][1]=A[k1][1];
            c[k3][2]=A[k1][2];
            k3++,k1++;
        }
        while(k2<=t2)
        {
            c[k3][0]=B[k2][0];
            c[k3][1]=B[k2][1];
            c[k3][2]=B[k2][2];
            k3++,k2++;
        }


        c[0][0]=A[0][0],c[0][1]=A[0][1],c[0][2]=k3-1;
        printf("Addition Matrix is:\n");
        for(int i=0; i<k3; i++)
        {
            for(int j=0; j<3; j++)
            {
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }

}
void triplet (int a[20][20],int row,int col,int a1[20][20],int row1,int col1)
{
    int nonzero=0,r=0,c=0,spar[20][20];
    int element;
    for(r=0; r<row; r++)
    {
        for(c=0; c<col; c++)
        {
            element=a[r][c];
            if(element!=0)
            {
                nonzero++;
                spar[nonzero][0]=r;
                spar[nonzero][1]=c;
                spar[nonzero][2]=element;
            }
        }
    }
    spar[0][0]=row;
    spar[0][1]=col;
    spar[0][2]=nonzero;
    int nonzero1=0,r1=0,c1=0,spar1[20][20];
    int element1;
    for(r1=0; r1<row1; r1++)
    {
        for(c1=0; c1<col1; c1++)
        {
            element1=a1[r1][c1];
            if(element1!=0)
            {
                nonzero1++;
                spar1[nonzero1][0]=r1;
                spar1[nonzero1][1]=c1;
                spar1[nonzero1][2]=element1;
            }
        }
    }
    spar1[0][0]=row1;
    spar1[0][1]=col1;
    spar1[0][2]=nonzero1;
    printf("Triplet representation-1\n");
    for(int i=0; i<=nonzero; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ",spar[i][j]);
        }
        printf("\n");
    }
    printf("Triplet representation-2\n");
    for(int i=0; i<=nonzero1; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ",spar1[i][j]);
        }
        printf("\n");
    }
    addition (spar,spar1);
}
int main()
{
    int a[20][20],m,n,p,q,b[20][20];
    printf("Enter the rows and columns of 1st matrix\n");
    scanf("%d%d",&m,&n);
    printf("Enter 1st matrix elements\n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the rows and columns of 2nd matrix\n");
    scanf("%d%d",&p,&q);
    printf("Enter 2nd matrix elements\n");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<q; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    triplet(a,m,n,b,p,q);

}