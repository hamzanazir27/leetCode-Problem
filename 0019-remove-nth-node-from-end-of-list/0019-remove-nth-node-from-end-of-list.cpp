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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            
    if(head->next ==nullptr)
    {
        ListNode* temp=head;
        if(head->next==nullptr)
           return nullptr; 
        head=head->next;
        delete temp;
        return head;
    }
           
    
     
    
    //calculate length
     ListNode* temp=head;
     int len=0;

     while(temp!=nullptr)
     {
        len++;
        temp=temp->next;

     }

     int nodeNo =len-n;
     len=0;
     temp=head;
      if(len ==nodeNo  )
        {

           ListNode* ptr =head->next;
           delete head;
           return ptr;

        
        }
     while(len+1!=nodeNo) 
     {
        len++;
        temp=temp->next;
 
     }

        ListNode*  temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;



    return head;
    }
};