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
