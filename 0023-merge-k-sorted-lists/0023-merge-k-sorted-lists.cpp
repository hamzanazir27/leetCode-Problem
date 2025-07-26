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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     if (lists.size()==1)
        return lists[0];
     if (lists.empty())
          return nullptr;




       int left=0;
      int right=0;
       for(right=1;right<lists.size(); right++)
       {
        lists[right]=handleSort(lists[left],lists[right]);
        left++;
       }


       return  lists[left];
       



       
    }

    ListNode* handleSort(ListNode* list1, ListNode* list2) {
        if (list1==nullptr) {
            return list2;
        }
        if (list2==nullptr) {
            return list1;
        }

        ListNode* head = new ListNode();
        ListNode* cur = head;
        while (list1 &&  list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                cur = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                cur = list1;
                list1 = list1->next;
            }
        }

        if(!list1)cur->next=list2;
        else  cur->next=list1;

        cur =head;
        head=cur->next;
        delete cur;
        return head;
    }//handlesort

    
     
};