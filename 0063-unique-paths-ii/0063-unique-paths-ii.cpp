// recursion  Solutuon   // >>>>>><><><><><>>>>>schduale
// ------><><<<><><><><><><><><><><>>>><<<<

class SolutionRecursion {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return helper(m - 1, n - 1, obstacleGrid);
    }

    int helper(int m, int n, vector<vector<int>>& obstacleGrid) {
        if (m < 0 || n < 0)
            return 0;

        if (m == 0 && n == 0) {
            if (obstacleGrid[m][n] == 1)
                return 0;
            else
                return 1;
        }

        if (obstacleGrid[m][n] == 1)
            return 0;

        return helper(m - 1, n, obstacleGrid) + helper(m, n - 1, obstacleGrid);

    } // helper
};

// DP Memorization

class SolutionMemorization {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, obstacleGrid, dp);
    }

    int helper(int m, int n, vector<vector<int>>& obstacleGrid,
               vector<vector<int>>& dp) {
        if (m < 0 || n < 0)
            return 0;

        if (m == 0 && n == 0) {
            if (obstacleGrid[m][n] == 1)
                return 0;
            else
                return 1;
        }

        if (obstacleGrid[m][n] == 1)
            return 0;
        if (dp[m][n] != -1)

        {
            return dp[m][n];
        }

        return dp[m][n] = helper(m - 1, n, obstacleGrid, dp) +
                          helper(m, n - 1, obstacleGrid, dp);

    } // helper
};
// DP Tabular Approch

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 1)
            return 0;
        // start point
        dp[0][0] = 1;

        // fill first row
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i-1][0];
        }
        // fill first coloumn
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1)
                dp[0][i] = 0;
            else
                dp[0][i] = dp[0][i-1];
        }



        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
               if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }
        }

        return dp[m - 1][n - 1];

    } // uniquePathsWithObstacles
};
