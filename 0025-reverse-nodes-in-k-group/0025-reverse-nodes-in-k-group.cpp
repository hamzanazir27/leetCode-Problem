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
        // add dummy node as a head
        ListNode* dummy = new ListNode();
        dummy->next = head;

        // previous Group End
        ListNode* prevGroupEnd = dummy;
        while (true) {
            // pointer which triverse whole LL
            ListNode* ptr = prevGroupEnd;
            int i = 0;

            // check condintion   [d]-[1]-[2]-[3]-[4]-[5]-[6]-[7]-[8]-[9]

            for (int i = 0; ptr != nullptr && i < k; i++) {
                ptr = ptr->next;
            }
            if (!ptr)
                break; // when link list comes to an end;

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = ptr->next;

            ListNode* cur = groupStart;
            ListNode* prev = nextGroupStart; // null

                while (cur !=nextGroupStart) {

                ListNode* n = cur->next;
                cur->next = prev;
                prev = cur;
                cur = n;
            }

            prevGroupEnd->next=prev;
            prevGroupEnd=groupStart;


        } 

        head = dummy->next;
        delete dummy;
        return head;
    }
};