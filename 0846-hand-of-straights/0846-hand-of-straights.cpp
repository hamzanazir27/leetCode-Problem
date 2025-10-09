/*
Understanding 
-------------




approch 
-------
*/


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() %groupSize!=0)
         return false ;

        map<int,int> count;

        for(int num:hand)
        {
          count[num]++;

        }
        for(auto ele:count)
        {
            int element=ele.first;
            int freq=ele.second;
// count = {1:1, 2:2, 3:2, 4:1, 6:1, 7:1, 8:1}

    if(freq==0) continue;

            for(int j=0;j<freq;j++)
            {
                for(int k=0;k<groupSize;k++)
                {
                  int  neededElemnt =element+k;
                    if(!count[neededElemnt] || count[neededElemnt] <=0)
                    {
                        return false;
                    }
                    count[neededElemnt]--;
      
                }//make group

            }//making posible groups for i-th elements
        }//itrating all elments 

        return true;

        
    }
};