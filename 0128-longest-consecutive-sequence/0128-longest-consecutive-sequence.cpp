class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sat(nums.begin(),nums.end());
        int longest=0;
        for(int num:sat)
        {
            if(sat.find(num-1)==sat.end())
            {
                int current=num;
                int length=1;
                while(sat.find(current+1)!=sat.end())
                {
                    current++;
                    length++;
                }
                 longest=max(length,longest);
            }
            
        }
return longest;
    }
};