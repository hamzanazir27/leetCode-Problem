class Solution {
    vector<string> alphabets = {"",    "",    "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {


        vector<string> finalresult;
        if (digits.empty())  // edge case: empty input
            return finalresult;

        string currentCombination = "";
        backTracking(digits, finalresult,  0, currentCombination);
        return finalresult;
    }

    void backTracking(string& digits, vector<string>& finalresult,
                      int currentIndex, string& currentCombination) {
        // base condition
        if (currentIndex == digits.size()) {
            finalresult.push_back(currentCombination);
            return;
        }

        // find number telephone digit number  it gives
        // character then - "0 convert to integer"
        int digNo = digits[currentIndex] - '0';
        // find letters on telephone digit no
        string letters = alphabets[digNo];

        for (char letter : letters) {
            // chose
            currentCombination += letter;

            // explore
            backTracking(digits, finalresult, currentIndex + 1,
                         currentCombination);

            // undo
            currentCombination.pop_back();
        }
    }
};