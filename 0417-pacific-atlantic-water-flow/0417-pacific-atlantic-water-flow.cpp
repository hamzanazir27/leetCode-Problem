class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Step 1: Do lists banao - track karne ke liye
        vector<vector<bool>> canReachPacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> canReachAtlantic(rows, vector<bool>(cols, false));
        
        // Step 2: Pacific ke edges se start karo
        // Top row (row 0)
        for(int col = 0; col < cols; col++) {
            checkPath(heights, canReachPacific, 0, col);
        }
        // Left column (col 0)  
        for(int row = 0; row < rows; row++) {
            checkPath(heights, canReachPacific, row, 0);
        }
        
        // Step 3: Atlantic ke edges se start karo
        // Bottom row (last row)
        for(int col = 0; col < cols; col++) {
            checkPath(heights, canReachAtlantic, rows-1, col);
        }
        // Right column (last col)
        for(int row = 0; row < rows; row++) {
            checkPath(heights, canReachAtlantic, row, cols-1);
        }
        
        // Step 4: Dono mein jo common hain, wo answer
        vector<vector<int>> answer;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    answer.push_back({i, j});
                }
            }
        }
        
        return answer;
    }
    
private:
    void checkPath(vector<vector<int>>& heights, vector<vector<bool>>& canReach, 
                   int row, int col) {
        // Already checked? Return
        if(canReach[row][col]) return;
        
        // Mark as reachable
        canReach[row][col] = true;
        
        int currentHeight = heights[row][col];
        int totalRows = heights.size();
        int totalCols = heights[0].size();
        
        // Check UP
        if(row > 0 && heights[row-1][col] >= currentHeight) {
            checkPath(heights, canReach, row-1, col);
        }
        
        // Check DOWN  
        if(row < totalRows-1 && heights[row+1][col] >= currentHeight) {
            checkPath(heights, canReach, row+1, col);
        }
        
        // Check LEFT
        if(col > 0 && heights[row][col-1] >= currentHeight) {
            checkPath(heights, canReach, row, col-1);
        }
        
        // Check RIGHT
        if(col < totalCols-1 && heights[row][col+1] >= currentHeight) {
            checkPath(heights, canReach, row, col+1);
        }
    }
};
