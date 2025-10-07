//recursion  Solutuon


class SolutionRecursion {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
  
    return   helper(m-1,n-1,obstacleGrid);

    }


    int helper(int m , int n,vector<vector<int>>& obstacleGrid )
    {
    if (m < 0 || n < 0) return 0;



  if (m == 0 && n == 0) {
    if (obstacleGrid[m][n] == 1)
        return 0;
    else
        return 1;
}


    if(obstacleGrid[m][n]==1)return 0;

    return helper(m-1,n,obstacleGrid) + helper(m,n-1,obstacleGrid);

    }//helper
};




//DP Memorization


class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
vector<vector<int>> dp(m, vector<int>(n, -1));
    return   helper(m-1,n-1,obstacleGrid,dp);

    }


    int helper(int m , int n,vector<vector<int>>& obstacleGrid ,vector<vector<int>>& dp)
    {
    if (m < 0 || n < 0) return 0;

  if (m == 0 && n == 0) {
    if (obstacleGrid[m][n] == 1)
        return 0;
    else
        return 1;
}


    if(obstacleGrid[m][n]==1)
    return 0;
    if (dp[m][n] != -1)

    {
        return dp[m][n];
    }

    return dp[m][n]=helper(m-1,n,obstacleGrid,dp) + helper(m,n-1,obstacleGrid,dp);

    }//helper
};