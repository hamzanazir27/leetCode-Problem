class SolutionRecursion {
public:
    int coinChange(vector<int>& coins, int amount) {
        int result = helper(coins, amount);

        return result != INT_MAX ? result : -1;
    }

    int helper(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;
        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int remain = helper(coins, amount - coins[i]);
            if (remain != INT_MAX) {
                mini = min(1 + remain, mini);
            }
        }
        return mini;
    }
};

// DP_Memorization
class Solution_DP_Memorization {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int result = helper(coins, amount, dp);
        return result != INT_MAX ? result : -1;
    }

    int helper(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;
        int mini = INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        for (int i = 0; i < coins.size(); i++) {
            int remain = helper(coins, amount - coins[i], dp);
            if (remain != INT_MAX) {
                mini = min(1 + remain, mini);
            }
        }

        return dp[amount] = mini;
    }
};
// DP_Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // Base case: 0 amount = 0 coins

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX)
                    dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
            }
        }

        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};