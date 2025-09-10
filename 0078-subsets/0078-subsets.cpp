class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
         vector<int> temp;
        
      backtracking(0,result,temp,nums);
      return result;
        
    }

    void backtracking(int i, vector<vector<int>>& result, vector<int>& temp, vector<int>& nums) 
    {
        if(i==nums.size())
        {
            result.push_back(temp);
            return ;
        }

        //chose 
        temp.push_back(nums[i]);
         
        // explore 
        backtracking(i+1,result,temp,nums);

        //undo 
        temp.pop_back();

        backtracking(i+1,result,temp,nums);

    }
};