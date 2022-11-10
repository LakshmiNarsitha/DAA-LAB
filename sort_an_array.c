int* sortArray(int* nums, int numsSize, int* returnSize){
  *returnSize=numsSize;  
  mergesort(nums, 0, numsSize-1);
  return nums;
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
