#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> q;  // Queue for BFS
        int fresh_count = 0;       // Fresh oranges count
        
        // STEP 1: Grid ko scan karo
        // Saare rotten oranges queue mein daalo aur fresh count karo
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});  // Rotten orange ko queue mein daalo
                }
                else if (grid[r][c] == 1) {
                    fresh_count++;    // Fresh oranges count karo
                }
            }
        }
        
        // Agar koi fresh orange hi nahi hai
        if (fresh_count == 0) {
            return 0;
        }
        
        int minutes = 0;
        // 4 directions: Right, Down, Left, Up
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // STEP 2: BFS karo
        while (!q.empty() && fresh_count > 0) {
            int size = q.size();  // Current minute ke saare rotten oranges
            
            // Current level (minute) ke saare oranges process karo
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                
                int r = curr.first;
                int c = curr.second;
                
                // 4 directions mein check karo
                for (int d = 0; d < 4; d++) {
                    int nr = r + directions[d][0];
                    int nc = c + directions[d][1];
                    
                    // Valid position hai aur fresh orange hai?
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && 
                        grid[nr][nc] == 1) {
                        
                        grid[nr][nc] = 2;      // Rotten bana do
                        fresh_count--;          // Fresh count kam karo
                        q.push({nr, nc});       // Queue mein daalo
                    }
                }
            }
            
            minutes++;  // Ek minute badhao
        }
        
        // STEP 3: Result return karo
        return (fresh_count == 0) ? minutes : -1;
    }
};