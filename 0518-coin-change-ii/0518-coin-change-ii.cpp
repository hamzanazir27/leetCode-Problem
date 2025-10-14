
//Recursion Approch 
class SolutionRecursion {

public:
    int change(int amount, vector<int>& coins) {
        
        return helper(coins,amount,0);
    }

    int helper(vector<int>& coins, int amount,int index)
    {
        if (amount == 0)
            return 1;  //1 way found
        if (index==coins.size())
            return 0;//no left coin
   
        int include = 0;
    if (coins[index] <= amount)
        include = helper(coins,amount-coins[index],index);


    int exclude =helper(coins,amount,index+1);


       return include + exclude ;
    }
};

//Memory Optimization
class Solution{

public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1)); 
        return helper(coins,amount,0,dp);
    }

    int helper(vector<int>& coins, int amount,int index,vector<vector<int>>& dp)
    {
        if (amount == 0)
            return 1;    // 1 way found
        if (index==coins.size())
            return 0;    // no left coin

        if(dp[index][amount] !=-1)
         return dp[index][amount];
   
        int include = 0;
    if (coins[index] <= amount)
        include = helper(coins,amount-coins[index],index,dp);


    int exclude = helper(coins,amount,index+1,dp);


       return dp[index][amount]=include + exclude ;
    }
};
