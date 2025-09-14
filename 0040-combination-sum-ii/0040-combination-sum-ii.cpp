class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentResult;

        // Sort candidates to handle duplicates properly
        sort(candidates.begin(), candidates.end());

        // currentSum
        int currentSum = 0;

        backtracking(candidates,result, currentResult, 0, target);
         return result;
        //
    }
    void backtracking(vector<int>& candidates, vector<vector<int>>& result, vector<int>& currentResult,
                      int start, int target) {
        if (0 == target) {
            result.push_back(currentResult);
            return;
        }

        if (target < 0) {
            return;
        }

        // loop based approch
        for (int i = start; i < candidates.size(); i++) {
            // skip statement for dublication
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // chose
            currentResult.push_back(candidates[i]);

            // explore          -> for removing dublication i+1 as an starting index
            backtracking(candidates,result, currentResult, i+1, target-candidates[i]);

                // undo
                currentResult.pop_back();
        }
    }
};



// []
//  ├── [1]
//  │    ├── [1,1] → [1,1,6] ✅
//  │    ├── [1,2] → [1,2,5] ✅
//  │    ├── [1,5]
//  │    ├── [1,6]
//  │    └── [1,7] ✅
//  ├── [2]
//  │    ├── [2,5]
//  │    └── [2,6] ✅
//  ├── [5]
//  ├── [6]
//  ├── [7] ✅
//  └── [10]
