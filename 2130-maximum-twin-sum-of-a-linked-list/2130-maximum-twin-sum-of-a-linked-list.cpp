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
    int pairSum(ListNode* head) {

          // find mid 
          ListNode* slow=head;
          ListNode* temp=head;
          ListNode* fast=head;


          while(fast  && fast->next)
          {
           temp=slow;
            slow=slow->next;

            fast=fast->next->next;

          }
           temp->next=nullptr;






          //reverse 2nd half
          ListNode* cur=slow;
          ListNode* prev=nullptr;


         while(cur)
         {
            ListNode* curNex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=curNex;
         }
        ListNode* head2nd=prev;          


          
            // head2nd
            //head

        //3rd calculate max twin
        int maxSum=0;
        


        while(head)
        {
         int sum=head2nd->val+head->val;
         maxSum =max(sum,maxSum);
         head=head->next;
        }

        return maxSum;
    }
};