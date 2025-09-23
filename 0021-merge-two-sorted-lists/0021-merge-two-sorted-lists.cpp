/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

       ListNode dummy(0);
       mergeAndSort( list1,  list2, &dummy);
       return dummy.next;
    }

void mergeAndSort(ListNode* list1, ListNode* list2,ListNode* sortedMerged)
{
    if(list1==nullptr && list2==nullptr)
    {
        return;
    }

    if(list1 &&  (!list2 || list1->val < list2->val))
    {
        sortedMerged->next=list1;
        mergeAndSort(list1->next, list2, sortedMerged->next);
    }
    else
    {
       sortedMerged->next=list2;
       mergeAndSort(list1, list2->next, sortedMerged->next);
    }
        


}


};