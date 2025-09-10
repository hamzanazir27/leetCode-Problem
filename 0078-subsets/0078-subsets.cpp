class Solution {
public:
    // Main function to generate all subsets of given array
    // Time Complexity: O(2^n * n) where n = nums.size()
    // Space Complexity: O(n * 2^n) for storing all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // Store all generated subsets
        vector<int> temp;            // Current subset being constructed
        
        // Start backtracking from index 0 with empty subset
        backtracking(0, result, temp, nums);
        return result;
    }
    
private:
    // Backtracking function using Include-Exclude approach
    // Each element has exactly 2 choices: include it OR exclude it
    // This creates a binary decision tree with 2^n leaf nodes (subsets)
    void backtracking(int i,                        // Current index in nums array
                     vector<vector<int>>& result,   // Reference to store all subsets
                     vector<int>& temp,             // Current subset being built
                     vector<int>& nums)             // Input array
    {
        // BASE CASE: We have processed all elements in the array
        // When i reaches nums.size(), we have made decisions for all elements
        // Current 'temp' represents one complete subset, so save it
        if(i == nums.size()) {
            result.push_back(temp);  // Add current subset to final result
            return;                  // Backtrack to try other combinations
        }
        
        // RECURSIVE CASE: Make binary decision for nums[i]
        
        // CHOICE 1: INCLUDE nums[i] in current subset
        // ===============================================
        temp.push_back(nums[i]);         // ✅ CHOOSE: Add current element
        backtracking(i+1, result, temp, nums);  // \U0001f504 EXPLORE: Recurse with next element
        temp.pop_back();                 // ❌ UNDO: Remove element (backtrack)
        
        // CHOICE 2: EXCLUDE nums[i] from current subset  
        // ===============================================
        // No need to add anything to temp, just move to next element
        backtracking(i+1, result, temp, nums);  // \U0001f504 EXPLORE: Recurse without adding current element
        
        // Why this works:
        // - First recursive call explores all subsets that INCLUDE nums[i]
        // - After backtracking (pop_back), temp is restored to previous state
        // - Second recursive call explores all subsets that EXCLUDE nums[i]
        // - This ensures we generate ALL possible combinations systematically
    }
};

/*
EXECUTION TRACE for nums = [1,2]:
=====================================

backtracking(0, [], [1,2])  // Decide about element 1
├── INCLUDE 1: temp = [1]
│   └── backtracking(1, [1], [1,2])  // Decide about element 2
│       ├── INCLUDE 2: temp = [1,2]
│       │   └── backtracking(2, [1,2], [1,2])  // i==2, BASE CASE
│       │       └── Save [1,2] ✅
│       └── UNDO 2: temp = [1]
│           └── backtracking(2, [1], [1,2])  // i==2, BASE CASE
│               └── Save [1] ✅
└── UNDO 1: temp = []
    └── backtracking(1, [], [1,2])  // Decide about element 2
        ├── INCLUDE 2: temp = [2]
        │   └── backtracking(2, [2], [1,2])  // i==2, BASE CASE
        │       └── Save [2] ✅
        └── EXCLUDE 2: temp = []
            └── backtracking(2, [], [1,2])  // i==2, BASE CASE
                └── Save [] ✅

FINAL RESULT: [[], [1], [2], [1,2]]

DECISION TREE VISUALIZATION:
============================
                i=0, temp=[]
               (decide about 1)
              /              \
     INCLUDE 1                EXCLUDE 1
   i=1, temp=[1]              i=1, temp=[]
  (decide about 2)           (decide about 2)
    /          \               /          \
INCLUDE 2    EXCLUDE 2     INCLUDE 2    EXCLUDE 2
temp=[1,2]   temp=[1]     temp=[2]     temp=[]
   |            |            |           |
Save [1,2]   Save [1]    Save [2]    Save []

KEY INSIGHTS:
=============
1. INCLUDE-EXCLUDE PATTERN: Perfect for subset/combination problems
2. BINARY DECISIONS: Each element has exactly 2 choices
3. SYSTEMATIC EXPLORATION: No subset is missed or duplicated
4. BACKTRACKING: Undo allows exploring alternative paths
5. TEMPLATE REUSABLE: Same pattern works for combination sum, subset sum etc.

COMPLEXITY ANALYSIS:
===================
- Time: O(2^n * n) 
  * 2^n subsets to generate
  * Each subset takes O(n) time in worst case
- Space: O(n * 2^n)
  * 2^n subsets in result
  * Average subset size is n/2
  * Recursion depth: O(n)
*/