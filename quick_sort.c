#include<stdio.h>
#include<stdlib.h>
void interchange(int arr[],int i,int j)
{
    int temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i = (low-1);
    for(int j=low;j<=high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            interchange(arr,i,j);
        }
    }
    interchange(arr,i+1,high);
    return (i+1);
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int m=partition(arr,low,high);
        quicksort(arr,low,m-1);
        quicksort(arr,m+1,high);
    }
}
void printArray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void main()
{
    int i,n;
    printf("enter no of elements in array : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting :\n");
    printArray(arr,n);
    printf("\n");
    quicksort(arr,0,n-1);
    printf("Array after sorting :\n");
    printArray(arr,n);
}
