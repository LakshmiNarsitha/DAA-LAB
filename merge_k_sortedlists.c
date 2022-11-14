#include <stdio.h>
#include<stdlib.h>
struct ListNode {
  int val;
  struct ListNode *next;
 };
 struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1==NULL)
    {
        return list2;
    }
    else if(list2==NULL)
    {
        return list1;
    }
    else if(list1->val<=list2->val)
    {
        list1->next=mergeTwoLists(list1->next,list2);
        return list1;
    }
    else
    {
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode* result=NULL;
    if(listsSize==0)
    {
        return NULL;
    }
    if(listsSize==1)
    {
        return lists[0];
    }
    for(int i=0;i<listsSize;i++)
    {
        result=mergeTwoLists(result,lists[i]);
    }
    return result;
}
struct ListNode* create(struct ListNode* first)
{
    struct ListNode *new,*prev;
    int x;
    printf("enter data,enter -1 to stop");
    scanf("%d",&x);
    while(x!=-1)
    {
        new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new ->val=x;
        new ->next=NULL;
        if(first==NULL)
        {
            first=new;
            prev=new;
        }
        else
        {
            prev ->next=new;
            prev=new;
        }
        printf("enter data");
        scanf("%d",&x);
    }
    return first;
}
void display(struct ListNode *first)
{
    struct ListNode *temp=first;
    if(first==NULL)
    {
        printf("[]");
    }
    else
    {
        printf("[");
        while(temp!=NULL)
        {
            printf("%d ,",temp ->val);
            temp = temp ->next;
        }
        printf("]");
    }
}

void main()
{
    struct ListNode *l;
    int listsSize;
    printf("Enter no of lists : ");
    scanf("%d",&listsSize);
    struct ListNode *lists[listsSize];
    printf("enter list elements : \n");
    for(int i=0;i<listsSize;i++)
    {
        lists[i]=NULL;
        lists[i]=create(lists[i]);
    }
    l=mergeKLists(lists,listsSize);
    if(l==NULL)
    {
        printf("[]");
    }
    else
    {
        display(l);
    }
}
