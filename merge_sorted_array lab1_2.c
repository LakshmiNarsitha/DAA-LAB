//https://leetcode.com/problems/merge-sorted-array/
#include<stdio.h>
#include<stdlib.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=m-1;
    int j=n-1;
    while(i>=0 && j>=0)
    {
        if(nums1[i]>nums2[j])
        {
            nums1[i+j+1]=nums1[i];
            i=i-1;
        }
        else
        {
            nums1[i+j+1]=nums2[j];
            j=j-1;
        }
    }
    while(j>=0)
    {
        nums1[i+j+1]=nums2[j];
        j=j-1;
    }
}
void main()
{
    int m,n;
    printf("enter no of elements in nums1");
    scanf("%d",&m);
    printf("enter no of elements in nums2");
    scanf("%d",&n);
    int nums1[m+n],nums2[n];
    printf("enter elements in nums1");
    for(int i=0;i<m;i++)
    {
    scanf("%d",&nums1[i]);
    }
    printf("enter elements in nums2");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&nums2[i]);
    }
    merge(&nums1[0],sizeof(nums1)/sizeof(int),m,&nums2[0],sizeof(nums2)/sizeof(int),n);
    printf("[");
    for(int i=0;i<(m+n);i++)
    {
    printf("%d,",nums1[i]);
    }
    printf("]");
}
