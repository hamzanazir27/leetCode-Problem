class Solution {






    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> result;
       vector<int> curResult;
               sort(nums.begin(), nums.end()); // step 1: sort to handle duplicates

               backtracking(0,nums,curResult, result);
               return result;


    }

    void backtracking(int index,vector<int>& nums,vector<int>& curResult,vector<vector<int>>& result)
    {
        //condition
       
          result.push_back(curResult);
       

     for(int i=index;i<nums.size();i++)
     { 
        if(i> index && nums[i]==nums[i-1])
        continue;


        //choise 
       curResult.push_back(nums[i]);
        //explore 
       backtracking( i+1,nums,curResult, result);

        //undo 
        curResult.pop_back();

        //explore


     }

    }
};