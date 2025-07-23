/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        //[_8] -> {} -> [ _1] ->{}  -> [_9] ->{} -> [_6] -> {}
        Node* temp = head;
        while (temp != nullptr) {
            Node* copy = new Node(temp->val);
            Node* temp2 = temp->next != nullptr ? temp->next : NULL;
            temp->next = copy;
            copy->next = temp2;
            temp = temp2;
        }

        // random assign
        //[_8] -> {} -> [ _1] ->{}  -> [_9] ->{} -> [_6] -> {}

        temp = head;
        while (temp != nullptr) {
            Node* copy = temp->next;
            // Node* temp2=temp->next != nullptr ?  temp->next :NULL;
            if (temp->random)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        //         //now deattach
        //   //[_8] -> {} -> [ temp _1] ->{copy}  -> [_9] ->{} -> [temp] ->
        //   {copy}
        Node* copyHead = head->next;
        temp = head;

        while (temp != nullptr) {

            Node* copy = temp->next;
            Node* temp2 = copy->next;
            copy->next = copy->next!= nullptr ? copy->next->next : nullptr;

            temp->next = temp2;
            temp = temp2;
        }



        return copyHead;
    }
};