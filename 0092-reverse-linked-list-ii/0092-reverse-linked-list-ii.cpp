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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;

        return reverseFind(head, 1, left, right);
    }

    ListNode* reverseFind(ListNode* head, int pos, int left, int right) {
        //    ListNode* tail=head;
        //    ListNode* current=head;
        //    ListNode* prev=nullptr;

        if (pos == left) {
            return reversedList(head, right - left + 1);
        }
head->next = reverseFind(head->next, pos + 1, left, right);
        return head;
    }

    ListNode* reversedList(ListNode* head, int range) {

        ListNode* tail = head;
        ListNode* current = head;
        ListNode* prev = nullptr;

         ListNode* next=nullptr;  // Store the tail to connect with remaining list
        

       
        for (int i = 0; i < range; i++) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        tail->next=current;


        return prev;








    }
};