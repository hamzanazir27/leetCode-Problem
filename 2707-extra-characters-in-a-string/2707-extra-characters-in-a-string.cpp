class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};

class Solution {
    TrieNode* root;

public:
    Solution() { root = new TrieNode(); }

    void addWord(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        for (auto& w : dictionary) addWord(w);

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            // option 1: skip character
            dp[i] = 1 + dp[i + 1];

            TrieNode* node = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!node->child[idx]) break;
                node = node->child[idx];

                if (node->isEnd) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};
