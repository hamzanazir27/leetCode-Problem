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
    ListNode* reverseList(ListNode* head) {
        //base head=null head=

        if(!head || !head->next)
          return head;


        //Minimum-Problem-------------|<--->| 
        ListNode*  newHead= reverseList(head->next);
        // newHead2=head->next;  like this but ye reverse ki hoi list se ata hai
        
         head->next->next=head;
         head->next=nullptr;


        //recursive realtion ship

        
         


        
        return newHead;







    }
};