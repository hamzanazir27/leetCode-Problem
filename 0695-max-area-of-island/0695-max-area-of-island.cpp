class Solution {
    int count=0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int row = grid.size();
        int col = grid[0].size();
        int mx = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // When we find land, that means a new island
                if (grid[i][j] == 1) {
                    count=0;
                    dfs(grid, i, j, row, col);
                    mx=max(mx,count);

                }
            }
        }
        return mx;
    }//maxAreaOfIsland

   void dfs(vector<vector<int>>& grid, int i, int j, int row, int col) {
        // Base Case: Out of bounds or water
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0)
            return ;

        // Mark as visited
        grid[i][j] = 0;
        count++;

        // Explore all four directions
        dfs(grid, i + 1, j, row, col); // down
        dfs(grid, i - 1, j, row, col); // up
        dfs(grid, i, j + 1, row, col); // right
        dfs(grid, i, j - 1, row, col); // left
    }
};