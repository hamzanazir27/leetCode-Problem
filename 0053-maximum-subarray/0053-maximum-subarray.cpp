/*
============================================================================
                    MAXIMUM SUBARRAY PROBLEM - COMPLETE GUIDE
============================================================================

PROBLEM UNDERSTANDING:
----------------------
- Find the contiguous subarray with the largest sum
- Input: Array of integers (can be positive, negative, or zero)
- Output: Maximum sum of any contiguous subarray

Example:
Input:  [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: [4, -1, 2, 1] has the largest sum = 6

VISUAL WALKTHROUGH:
-------------------
Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Step-by-step execution:
┌─────┬─────┬─────────┬─────────┬──────────────────┐
│ i   │ num │ sum     │ maxSum  │ Action           │
├─────┼─────┼─────────┼─────────┼──────────────────┤
│ 0   │ -2  │ 0→-2    │ -2      │ sum+=(-2)        │
│ 1   │ 1   │ 0→1     │ 1       │ sum<0, reset→1   │
│ 2   │ -3  │ 1→(-2)  │ 1       │ sum+=(-3)        │
│ 3   │ 4   │ 0→4     │ 4       │ sum<0, reset→4   │
│ 4   │ -1  │ 4→3     │ 4       │ sum+=(-1)        │
│ 5   │ 2   │ 3→5     │ 5       │ sum+=2           │
│ 6   │ 1   │ 5→6     │ 6       │ sum+=1           │
│ 7   │ -5  │ 6→1     │ 6       │ sum+=(-5)        │
│ 8   │ 4   │ 1→5     │ 6       │ sum+=4           │
└─────┴─────┴─────────┴─────────┴──────────────────┘

Final Answer: 6

ALGORITHM APPROACH (KADANE'S ALGORITHM):
----------------------------------------
Core Logic:
1. Track running sum of current subarray
2. Reset sum to 0 when it becomes negative (negative prefix hurts our answer)
3. Keep track of maximum sum seen so far
4. Continue until we process all elements

Why Greedy Works:
- Local Decision: "Should I include negative prefix or start fresh?"
- Greedy Choice: "Always discard negative prefix"
- Global Optimum: This leads to maximum possible sum

Proof: If we have [positive_sum] + [negative_prefix] + [remaining_array]
Since negative_prefix < 0, starting fresh gives better or equal results!

COMPLEXITY ANALYSIS:
-------------------
Time Complexity: O(n)
- Single pass through the array
- Each element is processed exactly once

Space Complexity: O(1)
- Only using constant extra space
- Variables: sum, maxSum

EDGE CASES:
-----------
1. All negative numbers: [-3, -2, -5, -1] → Returns -1 (least negative)
2. All positive numbers: [1, 2, 3, 4] → Returns 10 (sum of all)
3. Single element: [5] → Returns 5
4. Mixed: [-2, 1, -3, 4] → Returns 4

COMMON MISTAKES TO AVOID:
------------------------
1. Not initializing maxSum with nums[0] (fails for all-negative arrays)
2. Not resetting sum to 0 when it becomes negative
3. Using INT_MIN for initialization (can cause overflow)
4. Not handling empty arrays properly
*/



class Solution {
public:
    /*
    MAIN SOLUTION - KADANE'S ALGORITHM (GREEDY APPROACH)
    ===================================================
    
    Algorithm Steps:
    1. Initialize sum = 0 (current subarray sum)
    2. Initialize maxSum = nums[0] (handles all-negative case)
    3. For each element:
       - If sum < 0, reset sum = 0 (discard negative prefix)
       - Add current element to sum
       - Update maxSum if current sum is larger
    4. Return maxSum
    
    Why this works:
    - Negative prefix can never help us get maximum sum
    - Better to start fresh than carry negative baggage
    - Local optimal choice leads to global optimal solution
    */
    int maxSubArray(vector<int>& nums) {
        // Handle edge case: empty array
        if (nums.empty()) return 0;
        
        int sum = 0;                    // Current subarray sum
        int maxSum = nums[0];           // Maximum sum found so far (important for all-negative arrays)
        
        for (int no : nums) {
            // GREEDY DECISION: If current sum is negative, reset it
            // Reasoning: Negative prefix will only decrease our maximum sum
            // Better to start fresh from current element
            if (sum < 0) {
                sum = 0;
            }
            
            // Add current element to running sum
            sum += no;
            
            // Update maximum sum if current sum is larger
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
    
