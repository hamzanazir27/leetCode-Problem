class Solution {
public:
    bool checkValidString(string s) {
         int start=0; // ->(
        int end=0; // -> )
        for(char chr:s)
        {
            if(chr=='(')
            {
                start++;
                end++;
            }
            if(chr==')')
            {
                start--;
                end--;
            }
            if(chr=='*')
            {
                start--;
                end++;

            }
            if(end<0)
            return false;
            start=max(0,start);
            
        }

        return  start==0;
    
    }
};