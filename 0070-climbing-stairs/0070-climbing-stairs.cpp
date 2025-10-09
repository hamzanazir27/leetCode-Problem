// Recursion

class SolutionRecursion {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
// Dp approch Memorization

class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n + 1, -1);

        return helper(n, dp);
    }
    int helper(int n, vector<int>& dp) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
};