#include <stdio.h>
#include<stdlib.h>
void merge(int* nums, int l, int m, int r)
{
    int i,j;
    int k=l;
    int n1,n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++)
    {
        L[i]=nums[i+l];
    }
    for(j=0; j<n2; j++)
    {
        R[j]=nums[j+m+1];
    }
    i=j=0;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            nums[k]=L[i];
            i++;
        }
        else
        {
            nums[k]=R[j];
            j++;
        }
        k++;
        
    }
    while(i<n1)
    {
        nums[k]=L[i];
        i++;
        k++;
        
    }
    while(j<n2)
    {
        nums[k]=R[j];
        j++;
        k++;
    }  
}
void mergesort(int* nums,int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        mergesort(nums,l,m);
        mergesort(nums,m+1,h);
        merge(nums,l,m,h);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize){
  *returnSize=numsSize;  
  mergesort(nums, 0, numsSize-1);
  return nums;
}

void display(int *res,int n)
{
    int i=0;
    printf("The resulted array is:");
    for(i=0;i<n;i++)
    {
        printf("%d ",res[i]);
    }
}
void main()
{
    int n;
    printf("enter no of elements in array : ");
    scanf("%d",&n);
    int nums[n];
    printf("enter array elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    int *res=sortArray(nums,n,&n);
    display(res,n);
}
