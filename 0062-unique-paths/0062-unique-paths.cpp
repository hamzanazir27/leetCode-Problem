//reursion 


class SolutionRecursion {
public:
    int uniquePaths(int m, int n) {
        


        // mera kam hai bnta bar me ajye janta 
         if(m==1 or n==1)
          return 1;

        return uniquePaths(m-1,n)+uniquePaths(m,n-1);

    }
};
//dp top down approch memorization 


class Solution {
public:
    int uniquePaths(int m, int n) {
        
        unordered_map<string,int> dp;
        return helper(m,n,dp);


    }

    int helper(int m, int n,unordered_map<string,int>& dp)
    {
        


        
        // mera kam hai bnta bar me ajye janta 
         if(m==1 or n==1)
          return 1;

        if(dp[to_string(m)+to_string(n)])
        {
            return dp[to_string(m)+to_string(n)];
        }

        return dp[to_string(m)+to_string(n)]=helper(m-1,n,dp)+helper(m,n-1,dp);
    }
};