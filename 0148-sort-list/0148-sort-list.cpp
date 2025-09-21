/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
Step 1: Simplest Case (Base Case)


✅ Step 2: Try Examples

Example: [4,2,1,3]

Divide: [4,2] + [1,3]

Sort [4,2] → [2,4]

Sort [1,3] → [1,3]

Merge → [1,2,3,4]

Example: [5, -1, 3, 0]

Divide: [5, -1] + [3, 0]

Sort [5, -1] → [-1, 5]

Sort [3, 0] → [0, 3]

Merge → [-1, 0, 3, 5]
✅ Step 3: Relate Bigger Problem to Smaller

Kaise sort karenge badi list ko?

Agar mujhe chhoti list ka sorted version mil jaye, to main unhe merge kar sakta
hoon. Matlab: sortList(head) = merge( sortList(left_half), sortList(right_half)
)


//base case

//minimum


//oder of execution
1,2

//

 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // base case or minmum
        if (!head || !head->next)
            return head;

        // find mid convert two linklist
        ListNode* slow = head;
        ListNode* fast = head;

        while ( fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rightHalf = slow->next;
        slow->next = nullptr;
        ListNode* leftHalf = head;

        // minimum list
        ListNode* list1 = sortList(leftHalf);
        ListNode* list2 = sortList(rightHalf);

        ListNode* sorted = merge(list1, list2);

        return sorted;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);

        ListNode* temp = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else // 1->val>l2->val
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp=temp->next;

        }



        //loop end hoajye gi bu abi b  aik end pe aik node reh jaye gi os ko handle kiya
        temp->next = l1 ? l1 : l2;


        return dummy.next;

    }
};