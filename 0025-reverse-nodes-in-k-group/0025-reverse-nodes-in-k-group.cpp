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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Base case
        if (!head || !head->next)
            return head;

        // cehck if value of k is exist or not

        ListNode* node = head;
        int count = 0; 
        while (count < k) {
            if (!node)
                return head;
            node = node->next;
            count++;
        }

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* cur = head;
        int i = 0;
        while (i < k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            i++;
        }
        //cur == new head
        //head old === tail
         
         //node it's last index we found earlier
         head->next=reverseKGroup(node,  k) ;


         return prev;

          
         




    }
};