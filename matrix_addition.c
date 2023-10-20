#include<stdio.h>
void main()
{
	int i,j,nz=0,nz1=0,a[50][50],b[50][50],tripa[50][3],tripb[50][3],r1,c1,c2,r2,k,c[50][3];
    //matrix A
	printf("Enter the rows and columns of 1st matrix\n");
	scanf("%d%d",&r1,&c1);
	printf("Enter 1st matrix Elements:\n");
	for (i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	
    }
    printf("MATRIX A:\n");
 	for (i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
    }
    for (i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			if(a[i][j]!=0)
			{
				nz = nz+1;
				tripa[nz][0] = i;
				tripa[nz][1] = j;
				tripa[nz][2] = a[i][j];
              }
		}
	}
	tripa[0][0] = r1;
	tripa[0][1] = c1;
	tripa[0][2] = nz;
	printf("Triplet of A:\n");
	for(i=0;i<=nz;i++)
	{
		for(j =0;j<3;j++)
		{
			printf("%d\t",tripa[i][j]);
		}
		printf("\n");
	}
    //matrix B
	printf("Enter the rows and columns of 2nd matrix\n");
	scanf("%d%d",&r2,&c2);
    printf("Enter 2nd matrix Elements:\n");
 	for (i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			scanf("%d",&b[i][j]);
		}
    }
    printf("MATRIX B:\n");
 	for (i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
    }
      
    for (i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			if(b[i][j]!=0)
			{
				nz1 = nz1+1;
				tripb[nz1][0] = i;
				tripb[nz1][1] = j;
				tripb[nz1][2] = a[i][j];
			}
		}
	}
	tripb[0][0] = r2;
	tripb[0][1] = c2;
	tripb[0][2] = nz1;
	printf("Triplet of B:\n");
	for(i=0;i<=nz1;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",tripb[i][j]);
		}
		printf("\n");
	}
    //ADDITION MATRIX C
	if(r1==r2&&c1==c2)
	{
		i=1,j=1,k=1;
        while(i<=tripa[0][2]&&j<=tripb[0][2])
        {
            if(tripa[i][0]<tripb[j][0])
            {
            c[k][0]=tripa[i][0];
            c[k][1]=tripa[i][1];
            c[k][2]=tripa[i][2];
            k++;
            i++;
            }
            else if(tripa[i][0]>tripb[j][0])
            {
                c[k][0]=tripb[j][0];
                c[k][1]=tripb[j][1];
                c[k][2]=tripb[j][2];
                j++;
                k++;
            }
            else if(tripa[i][0]==tripb[i][0])
            {
                if (tripa[i][1]<tripb[j][1])
                {
                    c[k][0]=tripa[i][0];
                    c[k][1]=tripa[i][1];
                    c[k][2]=tripa[i][2];
                    k++;
                    i++;
                }
                else if (tripa[i][1]>tripb[j][1])
                {
                    c[k][0]=tripb[j][0];
                    c[k][1]=tripb[j][1];
                    c[k][2]=tripb[j][2];
                    k++;
                    j++;
                }
                else if(tripa[i][1]==tripb[j][1])
                {
                    c[k][0]=tripb[j][0];
                    c[k][1]=tripb[j][1];
                    c[k][2]=tripb[j][2]+tripa[i][2];
                    k++;
                    j++;
                    i++;
                }
            }

        }
        while(i<=tripa[0][2])
        {
            c[k][0]=tripa[i][0];
            c[k][1]=tripa[i][1];
            c[k][2]=tripa[i][2];
            k++;
            i++;
        }
        while(j<=tripb[0][2])
        {
            c[k][0]=tripb[j][0];
            c[k][1]=tripb[j][1];
            c[k][2]=tripb[j][2];
            k++;
            j++;
        }
        c[0][0]=tripa[0][0];
        c[0][1]=tripa[0][1];
        c[0][2]=k-1;
 
	}
    printf("%d",c[0][2]);
    printf("The Addition matrix is:\n");
    for(i=0;i<=c[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}