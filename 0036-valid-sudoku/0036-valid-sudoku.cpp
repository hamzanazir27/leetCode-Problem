class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(board, i) || !isValidCol(board, i))
                return false;
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValidSubBox(board, i, j))
                    return false;
            }
        }

        return true;
    }

private:
    bool isValidRow(vector<vector<char>>& board, int row) {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++) {
            char val = board[row][i];
            if (val == '.') continue;
            if (seen.count(val)) return false;
            seen.insert(val);
        }
        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col) {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++) {
            char val = board[i][col];
            if (val == '.') continue;
            if (seen.count(val)) return false;
            seen.insert(val);
        }
        return true;
    }

    bool isValidSubBox(vector<vector<char>>& board, int row, int col) {
        unordered_set<char> seen;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                char val = board[i][j];
                if (val == '.') continue;
                if (seen.count(val)) return false;
                seen.insert(val);
            }
        }
        return true;
    }
};
