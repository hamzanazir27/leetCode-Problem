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
    void reorderList(ListNode* head) {
        // if (head->next == nullptr)
        //     return head;

        // find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr &&
               fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        } // while end (slow and fast)

        // partition
        ListNode* LL2Head = slow->next;
        slow->next = nullptr;

        // Invert 2nd half
        ListNode* prev = nullptr;
        ListNode* temp = LL2Head;
        while (temp != nullptr) {
            // head -> tail=

            ListNode* nextN = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextN;
        }

        LL2Head = prev;
        temp = head;
        // concatinate
        while (LL2Head != nullptr && temp != nullptr) {

            ListNode* LL2N = LL2Head->next;
            ListNode* LL1N = temp->next;
            temp->next = LL2Head;

            LL2Head->next = LL1N;
            temp = LL1N;
            LL2Head = LL2N;
        }

        //  return rO;
    }
};