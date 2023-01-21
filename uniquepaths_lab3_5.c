#include<stdio.h>
#include<stdlib.h>
int uniquepaths(int m,int n)
{
        int a[n][m];
        int i,j;
        a[0][0]=0;
        for(i=1;i<n;i++)
        {
                a[i][0]=1;
        }
        for(j=1;j<m;j++)
        {
                a[0][j]=1;
        }
        for(i=1;i<n;i++)
        {
                for(j=1;j<m;j++)
                {
                        a[i][j]=a[i-1][j]+a[i][j-1];

                }
        }
        return a[n-1][m-1];
}
void main()
{
        int m,n;
        printf("enter no of rows : ");
        scanf("%d",&m);
        printf("enter no of columns : ");
        scanf("%d",&n);
        int k=uniquepaths(m,n);
        printf("No of possible ways : %d\n",k);
}
