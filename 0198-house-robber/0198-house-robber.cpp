class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums.size()-1, nums, dp);
    }

    int helper(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];

        if (dp[i] != -1) return dp[i];

        int pick = nums[i] + helper(i-2, nums, dp);
        int notPick = helper(i-1, nums, dp);

        return dp[i] = max(pick, notPick);
    }
};
