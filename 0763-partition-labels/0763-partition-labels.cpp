class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastindexofchar;
        for (int i = 0; i < s.size(); i++) {
            lastindexofchar[s[i]] = i;
        }

        int start = 0;
        int end = 0;
        vector<int> result;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastindexofchar[s[i]]);

            if (end == i) {
                result.push_back((end - start)+1);
                start=i+1;
            }
        }

        return result;
    }
};