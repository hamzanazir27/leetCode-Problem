class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      sort(deck.begin(), deck.end());
       deque<int> dq;

       for(int i=deck.size()-1;i>=0;i--)
       {
           if(!dq.empty())
           {
            int back_ele=dq.back();
            dq.pop_back();
            dq.push_front(back_ele);



           }

           dq.push_front(deck[i]);

 
        
       }

        
        //convert deque to array
        vector<int> result(dq.begin(), dq.end());

        return result;


    

    }
};