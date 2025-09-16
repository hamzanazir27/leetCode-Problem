/*

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string>> curResult;
        backtracking(n,curResult,result)
    }

   void backtracking(int n,vector<vector<string>>& result,vector<string>>&
curResult)
    {
        //condition




        for(int i=start;i<n;i++)
        {
            //condition


            //chose

            //backtrack

            //undo
        }




    }
};


*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        // vector<string> curResult(n, string(n, "."));
        vector<string> curResult(n, string(n, '.')); // n x n empty board

        // . . . .
        // . . . .
        // . . . .
        // . . . .

        backtracking(n, 0, result, curResult);
        return result;
    }

    void backtracking(int n, int row, vector<vector<string>>& result,
                      vector<string>& curResult) {
        // condition
        if (row == n) {
            result.push_back(curResult);
            return;
        }

        for (int col = 0; col < n; col++) {
            // condition
            if (queenExistInthisColOrDignonal(n, row, col, curResult))
                continue;

            // chose
            curResult[row][col] = 'Q';

            // backtrack
            backtracking(n, row + 1, result, curResult);

            // undo
            curResult[row][col] = '.';
        }
    }

    bool queenExistInthisColOrDignonal(int n, int row, int col,
                                       vector<string>& curResult) {
        // check this col exist or not
        for (int i = 0; i < row; i++) {
            if (curResult[i][col] == 'Q')
                return true;
        }
        //    check left dignol
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (curResult[i][j] == 'Q')
                return true;
        }

        // i === row and j== col  right diagnol

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (curResult[i][j] == 'Q')
                return true;
        }

        return false;
    }
};