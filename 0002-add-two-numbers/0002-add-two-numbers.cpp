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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addNumber( l1, l2, 0); 
    }

    ListNode* addNumber(ListNode* l1, ListNode* l2, int carry) {

        // step 1 minmimum problem
        if (!l1 && !l2 && carry == 0)
            return nullptr;

        // oder of exectuion  and relationship
        int a = l1!=nullptr ? l1->val : 0;
        int b = l2!=nullptr ? l2->val : 0;
        int sum = a + b + carry;

        ListNode* node =new ListNode(
            sum % 10, addNumber(l1?l1->next:nullptr, l2?l2->next:nullptr, sum / 10));
        return node;
    }
};