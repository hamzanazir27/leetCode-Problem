class SolutionRecursion {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(helper(cost, 0), helper(cost, 1));
    }

    int helper(vector<int>& cost, int index) {
        if (index >= cost.size())
            return 0;

        return min(cost[index] + helper(cost, index + 1),
                   cost[index] + helper(cost, index + 2));
    }
};

// approch 2 dp memorization
class SolutionMemorization {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);

        return min(helper(cost, 0, dp), helper(cost, 1, dp));
    }

    int helper(vector<int>& cost, int index, vector<int>& dp) {
        if (index >= cost.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];

        return dp[index] = min(cost[index] + helper(cost, index + 1, dp),
                               cost[index] + helper(cost, index + 2, dp));
    }
};
// approch 3 dp Tabulation approch
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        ///////////////////////////
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[cost.size()-1] ,dp[cost.size()-2]) ;
    }
};