class Solution {
public:
    string minWindow(string s, string t) {
       if (t.size() > s.size()) return "";

        unordered_map<char, int> t_count;
        for (char c : t) t_count[c]++;

        int required = t_count.size();
        unordered_map<char, int> window_count;

        int left = 0, right = 0, formed = 0;
        int min_len = INT_MAX, min_start = 0;

        while (right < s.size()) {
            char c = s[right];
            window_count[c]++;
            if (t_count.count(c) && window_count[c] == t_count[c])
                formed++;

            while (formed == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }

                char left_char = s[left];
                window_count[left_char]--;
                if (t_count.count(left_char) && window_count[left_char] < t_count[left_char])
                    formed--;

                left++;
            }
            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};