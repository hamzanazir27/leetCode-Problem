class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isvalid(left + 1, right, s) || isvalid(left, right - 1, s);
            }
            left++;
            right--;
        }
        return true;
    }

private:
    bool isvalid(int left, int right, string s) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
