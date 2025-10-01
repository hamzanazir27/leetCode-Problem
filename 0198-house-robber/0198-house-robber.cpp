// recursion approch 


class Solution3 {
public:
    int rob(vector<int>& nums) {
        return helper(nums.size()-1, nums);
        
    }

    int helper(int index,vector<int>& nums)
    {
if(index==0) return nums[0];
if(index==1) return max(nums[0], nums[1]);  

        

        int rob=nums[index]+helper(index-2,nums);
        int skip=helper(index-1,nums);


        return max(skip , rob);
                   
    }
};

//1st dp memorization approch of db (topdown apptoch)

class Solution2 {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums.size()-1, nums,dp);
        
    }

    int helper(int index,vector<int>& nums,vector<int> &dp)
    {
  if(index==0) return nums[0];
    if(index==1) return max(nums[0], nums[1]);  

        if(dp[index]!=-1)
        {
            return dp[index];
        }

        int rob=nums[index]+helper(index-2,nums,dp);
        int skip=helper(index-1,nums,dp);


        return dp[index]=max(skip , rob);
                   
    }
};

//2nd  dp tabular approch of db (bottom up apptoch)

class Solution{
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n);

    dp[0]= nums[0];
    dp[1]= max(nums[0], nums[1]); 
             
     for (int i=2;i<nums.size();i++)
     {
        dp[i]=max((nums[i]+dp[i-2]),dp[i-1]);
     }



     return dp[nums.size()-1];
        
    }

};




// /*
// Problem: 198. House Robber

// Classic DP problem where we need to make optimal decisions with constraints.
// At each house, we decide whether to rob it or not based on maximum profit.
// */

// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     // Approach 1: Recursion (Brute Force)
//     // Time: O(2^n), Space: O(n) - recursion stack
//     int robRecursion(vector<int>& nums) {
//         return robRecursionHelper(nums, 0);
//     }
    
// private:
//     int robRecursionHelper(vector<int>& nums, int index) {
//         if (index >= nums.size()) return 0;
//         // Choice: rob current house or skip it
//         int rob = nums[index] + robRecursionHelper(nums, index + 2);
//         int skip = robRecursionHelper(nums, index + 1);
//         return max(rob, skip);
//     }
    
// public:
//     // Approach 2: Memoization (Top-Down DP)
//     // Time: O(n), Space: O(n) - memoization table + recursion stack
//     int robMemo(vector<int>& nums) {
//         unordered_map<int, int> memo;
//         return robMemoHelper(nums, 0, memo);
//     }
    
// private:
//     int robMemoHelper(vector<int>& nums, int index, unordered_map<int, int>& memo) {
//         if (index >= nums.size()) return 0;
//         if (memo.find(index) != memo.end()) return memo[index];
        
//         int rob = nums[index] + robMemoHelper(nums, index + 2, memo);
//         int skip = robMemoHelper(nums, index + 1, memo);
//         memo[index] = max(rob, skip);
//         return memo[index];
//     }
    
// public:
//     // Approach 3: Tabulation (Bottom-Up DP)
//     // Time: O(n), Space: O(n) - DP array
//     int robTabulation(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];
        
//         vector<int> dp(n);
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
        
//         for (int i = 2; i < n; i++) {
//             dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
//         }
//         return dp[n-1];
//     }
    
//     // Approach 4: Space Optimization
//     // Time: O(n), Space: O(1) - only two variables
//     int robOptimized(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];
        
//         int prev2 = nums[0];
//         int prev1 = max(nums[0], nums[1]);
        
//         for (int i = 2; i < n; i++) {
//             int current = max(prev1, prev2 + nums[i]);
//             prev2 = prev1;
//             prev1 = current;
//         }
//         return prev1;
//     }
    
//     // Main function - using the most optimal approach
//     int rob(vector<int>& nums) {
//         return robOptimized(nums);
//     }
// };