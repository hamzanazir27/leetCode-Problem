class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* first = head;
        ListNode* second = head->next;

        // recursive call on the rest of the list
        first->next = swapPairs(second->next);

        // swap first and second
        second->next = first;

        return second;  // new head of the swapped pair
    }
};
