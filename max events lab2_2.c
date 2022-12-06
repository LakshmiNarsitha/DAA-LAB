//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
#include <stdio.h>
#include<stdlib.h>
void sortArray(int** pArray,int n)
{
    int i,j;
    int *temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pArray[i][1]>pArray[j][1])
            {
                temp=pArray[i];
                pArray[i]=pArray[j];
                pArray[j]=temp;
            }
        }
    }
}
int maxi(int** events,int eventsSize)
{
    int maxim=events[0][0];
    for(int i=0;i<eventsSize;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(maxim<events[i][j])
            {
                maxim=events[i][j];
            }
        }
    }
    return maxim;
}
int maxime(int** events,int k)
{
    if(events[k][0]<events[k][1])
    {
        return events[k][0];
    }
    else
    {
        return events[k][1];
    }
}
int maxEvents(int** events, int eventsSize, int* eventsColSize){
    int i,j;
    int maxim=maxi(events,eventsSize);
    sortArray(events,eventsSize);
    int c=0;
    int d;
    int arr[maxim];
    for(int i=0;i<maxim;i++)
    {
        arr[i]=-1;
    }
    for(int i=0;i<eventsSize;i++)
    {
        d=maxime(events,i)-1;
        if(arr[d]==-1)
        {
            arr[d]=1;
            c=c+1;
        }
        else
        {
            for(int j=events[i][0]-1;j<events[i][1];j++)
            {
                if(arr[j]==-1)
                {
                    arr[j]=1;
                    c++;
                    break;
                }
            }
        }
    }
    return c;
}
void main()
{
    int n,ecs;
    printf("enter no of events : ");
    scanf("%d",&n);
    printf("enter no of elements :");
    scanf("%d",&ecs);
    int** arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        arr[i] = (int*)malloc(ecs * sizeof(int));
    }
    printf("enter elements : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<ecs;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int ans=maxEvents(arr,n,&ecs);
    printf("Maximum no of events that can be attended is : %d",ans);
}
