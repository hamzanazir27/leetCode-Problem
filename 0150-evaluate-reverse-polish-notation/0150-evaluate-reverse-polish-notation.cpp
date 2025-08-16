/*
Understanding
-------------
Given a list of daily temperatures, for each day you must find how many days you would have to wait until a warmer temperature.
If there is no future day for which this is possible, put 0 for that day.

Approach
--------
- Iterate from right to left.
- Maintain a stack of indices where temperatures are strictly decreasing.
- For each day:
    1. Pop all days from stack that are not warmer than current day.
    2. If stack is not empty, answer = (stack.top() - i).
    3. Push current day's index onto stack.
- This ensures O(n) time complexity because each element is pushed/popped at most once.

Template
--------
1. Initialize a stack<int> to store indices.
2. Iterate backwards through temperatures.
3. Pop until a warmer temperature is found.
4. Fill ans[i] with (stack.top() - i) if found, else 0.
5. Push current index.

Complexity
----------
- Time Complexity: O(n) → Each element is pushed and popped at most once.
- Space Complexity: O(n) → For the stack + answer array.

----------------------------------------------------------------
Python Solution
---------------




class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        ans = [0] * n
        stack = []
        
        for i in range(n - 1, -1, -1):
            while stack and temperatures[i] >= temperatures[stack[-1]]:
                stack.pop()
            
            if stack:
                ans[i] = stack[-1] - i
            stack.append(i)
        
        return ans




----------------------------------------------------------------
JavaScript Solution
-------------------
var dailyTemperatures = function(temperatures) {
    let n = temperatures.length;
    let ans = new Array(n).fill(0);
    let stack = [];
    
    for (let i = n - 1; i >= 0; i--) {
        while (stack.length && temperatures[i] >= temperatures[stack[stack.length - 1]]) {
            stack.pop();
        }
        if (stack.length) {
            ans[i] = stack[stack.length - 1] - i;
        }
        stack.push(i);
    }
    return ans;
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk; // will store indices
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            // Pop all days that are colder or equal to current day
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }

            // If stack is not empty, next warmer day is at stk.top()
            if (!stk.empty()) {
                ans[i] = stk.top() - i;
            }

            // Push current day index
            stk.push(i);
        }
        return ans;
    }
};
