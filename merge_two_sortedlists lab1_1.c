//https://leetcode.com/problems/merge-two-sorted-lists/
#include<stdio.h>
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
        printf("no list to print");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d ,",temp ->val);
            temp = temp ->next;
        }
    }
}
void main()
{
    struct ListNode *l1=NULL,*l2=NULL,*k;
    printf("enter list1 : \n");
    l1=create(l1);
    printf("enter list2 : \n");
    l2=create(l2);
    k=mergeTwoLists(l1,l2);
    display(k);
}
