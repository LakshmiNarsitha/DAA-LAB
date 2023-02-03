https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int lengthOfLongestSubstring(char * s){
    int n=strlen(s);
    int res=0,p=0;
    int visited[500];
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<500;i++)
        {
        visited[i]=0;
        }
        p=0;
        for(int j=i;j<n;j++)
        {
            if(visited[s[j]]==0)
           {
              visited[s[j]]=1;
              p=p+1;
           }
           else
           {
            break;
           }   
        }
        res=max(res,p);
    }
    return res;
}
int main()
{
    int n;
    printf("enter length of strng : ");
    scanf("%d",&n);
    char s[n];
    printf("enter string : ");
    scanf("%s",s);
    int k=lengthOfLongestSubstring(s);
    printf("Length of longest common subsequence is : %d",k);
}
