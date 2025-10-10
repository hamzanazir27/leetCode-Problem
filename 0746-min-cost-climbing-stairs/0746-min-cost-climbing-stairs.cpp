class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
                vector<int> dp(cost.size(), -1);

        return min(helper(cost,0,dp),helper(cost,1,dp));

    }

    int helper(vector<int>& cost,int index,vector<int>& dp) {
        if(index>=cost.size())
            return 0;
        if(dp[index] !=-1)
           return dp[index];

       return dp[index]=min(cost[index]+helper(cost,index+1,dp),cost[index]+helper(cost,index+2,dp));
    }

};