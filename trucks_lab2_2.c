https://leetcode.com/problems/maximum-units-on-a-truck/
#include<stdio.h>
#include<stdlib.h>
void SortArray( int ** pArray, int ArrayLength )
{
    int i, j;
    int * temp;            
    for(i = 0; i <ArrayLength-1; i++)
    {
        for(j = i+1; j <ArrayLength; j++){
             if(pArray[i][1]<pArray[j][1]){
                 temp=pArray[i];
                 pArray[i]=pArray[j];
                 pArray[j]=temp;
                 
             }
        }
    }
}
int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    int i,c=0;
    SortArray(boxTypes,boxTypesSize);
    int remwt=truckSize;
    for(i=0;i<boxTypesSize;i++){
      if(remwt>=boxTypes[i][0]){
        c=c+(boxTypes[i][1]*boxTypes[i][0]);
       
      }
      else{
             c=c+(boxTypes[i][1]*remwt);
             break;
      }
      remwt=remwt-boxTypes[i][0];
     
}
  return c;  
}
int main(){
    int r,c,ts,i, j;
    printf("enter no of boxes : \n");
    scanf("%d",&r);
    printf("enter no of elements : \n");
    scanf("%d",&c);
    printf("ënter truck size : \n");
    scanf("%d",&ts);
    printf("enter elements :\n");
    int** arr = (int**)malloc(r * sizeof(int*));
    for (i = 0; i < r; i++)
        arr[i] = (int*)malloc(c * sizeof(int));
 
   
   
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d",&arr[i][j]);
 
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("After sorting : \n");
    SortArray(arr,r);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
        printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
   printf("Maximum Units on a Trucks are:%d",maximumUnits(arr,r,&c,ts));
   printf("\n");
   return 0;
   
}
