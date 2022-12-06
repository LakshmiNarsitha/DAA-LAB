//https://leetcode.com/problems/coin-change/description/
#include <stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int coinChange(int* coins, int coinsSize, int amount){
    int array[amount+1];
    array[0]=0;
    int i,j;
    for(i=1;i<amount+1;i++)
    {
        array[i]=amount+1;
    }
    for(i=1;i<amount+1;i++)
    {
        for(j=0;j<coinsSize;j++)
        {
            if(coins[j]<=i)
            {
                array[i]=min(array[i],1+array[i-coins[j]]);
            }
        }
    }
    if(array[amount]==(amount+1))
    {
        return -1;
    }
    else
    {
        return array[amount];
    }
}
void main()
{
    int n,amount;
    printf("enter coins size : ");
    scanf("%d",&n);
    printf("enter amount :");
    scanf("%d",&amount);
    int* arr=(int*)malloc(n*sizeof(int));
    printf("enter elements : \n");
    for(int i=0;i<n;i++)
    {
            scanf("%d",&arr[i]);
    }
    int ans=coinChange(arr,n,amount);
    printf("Minimum no of coins required is : %d",ans);
}
