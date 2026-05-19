class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> list;
        for(int i=0;i<nums.size();i++)
        { 
         int temp=target-nums[i];
          if(list.find(temp)!=list.end())
          {
            return {list[temp],i};
          }

          list[nums[i]]=i;
           
        }
        return {};
    }
};