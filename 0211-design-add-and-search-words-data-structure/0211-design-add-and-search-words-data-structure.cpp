class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

    bool searchHelper(string& word, int index, TrieNode* node) {
        if (!node) return false;

        // end of word
        if (index == word.size()) return node->isEnd;

        char c = word[index];

        if (c == '.') {
            // try all possible children
            for (int i = 0; i < 26; i++) {
                if (node->children[i] &&
                    searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int pos = c - 'a';
            return searchHelper(word, index + 1, node->children[pos]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
