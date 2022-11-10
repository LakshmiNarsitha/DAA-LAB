#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int low,int mid,int high)
{
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[low+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[mid+j+1];
    }
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    mergesort(arr,0,n-1);
    printf("Array after sorting :\n");
    printArray(arr,n);
}
