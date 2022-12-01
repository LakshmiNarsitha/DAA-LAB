#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    int max=10000;
    int i,j,u,v,w;
    int *dist=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        dist[i]=max;
    }
    dist[k-1]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<timesSize;j++)
        {
            u=times[j][0]-1;
            v=times[j][1]-1;
            w=times[j][2];
            dist[v]=min(dist[v],dist[u]+w);
        }
    }
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(dist[i]==max)
        {
            return -1;
        }
        ans=fmax(ans,dist[i]);
    }
    return ans;
}
int main()
{
    int n,k,ts,tcs,i,j;
    printf("enter no of nodes(n) : ");
    scanf("%d",&n);
    printf("enter starting node(k) : ");
    scanf("%d",&k);
    printf("enter no of edges : ");
    scanf("%d",&ts);
    printf("enter no of elements : ");
    scanf("%d",&tcs);
    printf("enter elements : \n");
    int** arr = (int**)malloc(ts * sizeof(int*));
    for (i = 0; i < n; i++)
        arr[i] = (int*)malloc(tcs * sizeof(int));
 
    for (i = 0; i <ts; i++)
        for (j = 0; j < tcs; j++)
            scanf("%d",&arr[i][j]);
    int ans=networkDelayTime(arr,ts,&tcs,n,k);
    printf("Minimum time is : %d",ans);
}
