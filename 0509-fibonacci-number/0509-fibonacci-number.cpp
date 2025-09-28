
//recursion
class Solution3 {
public:
    int fib(int n) {
        if(n<=1)
           return n;
        
        return fib(n-1)+fib(n-2);
    }
};

//dp topdown approch /. Memoization Approach ✅

class Solution2 {
public:
    int fib(int n) {
     vector<int> dp(n+1,-1);
     return helper(n,dp);
    }

    int helper(int n, vector<int> &dp)
    {
        if(n<=1)
           return n;

        if(dp[n] !=-1)
          return dp[n];
        
        return dp[n]=helper(n-1,dp)+helper(n-2,dp);
    }
};



//2. Tabulation Approach 
class Solution1 {
public:
    int fib(int n) {
     vector<int> dp(n+1,-1);

        if(n<=1)
           return n;
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};



//3. Space Optimized Approach 
class Solution {
public:
    int fib(int n) {
     vector<int> dp(n+1,-1);

        if(n<=1)
           return n;
        int prev1=1;
        int prev2=0;
        for(int i=2;i<=n;i++)
        {
            int cur=prev1+prev2;
            prev2=prev1;
            prev1=cur;
        }
        
    return prev1;
    }
};


