class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1window, s2window;
        if (s1.size() > s2.size())
            return false;
        for (char c : s1)
            s1window[c]++;

        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            s2window[s2[right]]++;

            if (right - left + 1 > s1.size()) {
                s2window[s2[left]]--;
                if (s2window[s2[left]] == 0) {
                    s2window.erase(s2[left]);
                    
                }
                left++;
            }
            if (right - left + 1 == s1.size() && s1window == s2window)
                    return true;
        }
        return false;
    }
};