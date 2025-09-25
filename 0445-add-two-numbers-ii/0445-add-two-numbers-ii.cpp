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
        
ListNode* reversel1=reverseList(l1);
ListNode* reversel2=reverseList(l2);
ListNode* result=addNumbers(reversel1,reversel2);
return reverseList(result);
    




    }
   ListNode* addNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
    // Base case
    if (!l1 && !l2 && carry == 0)
        return nullptr;

    // Extract values safely
    int a = (l1 ? l1->val : 0);
    int b = (l2 ? l2->val : 0);

    // Calculate digit and carry
    int sum = a + b + carry;
    int digit = sum % 10;
    int nextCarry = sum / 10;

    // Recursive call on next nodes
    ListNode* next1 = (l1 ? l1->next : nullptr);
    ListNode* next2 = (l2 ? l2->next : nullptr);

    ListNode* result = new ListNode(digit);
    result->next = addNumbers(next1, next2, nextCarry);

    return result;
}



    ListNode* reverseList(ListNode* l1) {


        if(!l1 ||!l1->next)
        return l1;

        // []-.[]<-[]<-[]->[] 

        ListNode* newhead=reverseList(l1->next);
        
        l1->next->next =l1;
        l1->next =nullptr;

        return newhead;
          


    }
};