class Solution {
public:
    // 1. Define the Trie Node Structure
    struct TrieNode {
        TrieNode* children[26];
        string* word; // Pointer to the word to avoid string copying

        TrieNode() {
            word = nullptr;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    // 2. Insert words into the Trie
    void insert(TrieNode* root, string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int index = c - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->word = &s; // Mark the end of a word
    }

    // 3. DFS / Backtracking traversal
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        
        // Base case: visited cell ('#') or no child in Trie matches current char
        if (c == '#' || !node->children[c - 'a']) return;

        TrieNode* nextNode = node->children[c - 'a'];

        // Check if we found a word
        if (nextNode->word != nullptr) {
            result.push_back(*nextNode->word);
            nextNode->word = nullptr; // Deduplicate: Mark as null so we don't add it again
        }

        // Mark current cell as visited
        board[i][j] = '#'; 

        // Explore neighbors (Up, Down, Left, Right)
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
                dfs(board, ni, nj, nextNode, result);
            }
        }

        // Backtrack: Restore the cell
        board[i][j] = c; 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        // Build the Trie
        for (string& w : words) {
            insert(root, w);
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        // Iterate through every cell in the grid to start DFS
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};