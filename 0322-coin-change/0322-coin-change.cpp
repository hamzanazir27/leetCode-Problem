// approch 1recurson


class Solution3 {
public:
    int coinChange(vector<int>& coins, int amount) {
     int result= helper(coins ,amount);
     return result==INT_MAX?-1:result;
    }

   int helper(vector<int>& coins, int amount)
   {
        if (amount == 0) return 0;          // base case
        if (amount < 0) return INT_MAX; 
    int minVal=INT_MAX;
    for(int coin:coins)
    {
        int remain=helper(coins,amount-coin);
        if(remain!=INT_MAX)
        {
            minVal=min(minVal,1+remain);
        }
    }
     return minVal;
   }


};
// approch 2 dp  


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     unordered_map<int,int> dp;


     int result= helper(coins ,amount,dp);
     return result==INT_MAX?-1:result;
    }

   int helper(vector<int>& coins, int amount,unordered_map<int,int> & dp)
   {
        if (amount == 0) return 0;          // base case
        if (amount < 0) return INT_MAX; 
       if(dp[amount] && dp[amount]!=-1)
       {
        return dp[amount];
       }

    int minVal=INT_MAX;
    for(int coin:coins)
    {
        int remain=helper(coins,amount-coin,dp);
        if(remain!=INT_MAX)
        {
            minVal=min(minVal,1+remain);
        }
    }
     return dp[amount]=minVal;
   }


};