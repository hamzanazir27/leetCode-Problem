/*
Understanding
-------------
Given a list of daily temperatures, for each day you must find how many days you would have to wait until a warmer temperature.
If there is no future day for which this is possible, put 0 for that day.

Approach
--------
- We will iterate from right to left.
- Maintain a stack of indices where temperatures are strictly decreasing.
- For each day:
    1. Pop all days from stack that are not warmer than current day.
    2. If stack is not empty, answer is difference in indices.
    3. Push current day's index onto stack.
- This ensures O(n) time complexity.

Template
--------
1. Initialize a stack<int> to store indices.
2. Iterate backwards through temperatures.
3. Pop until a warmer temperature is found.
4. Fill ans[i] with (stack.top() - i) if found, else 0.
5. Push current index.
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

/*
Python code
-----------
def dailyTemperatures(temperatures):
    n = len(temperatures)
    ans = [0] * n
    stk = []
    for i in range(n - 1, -1, -1):
        while stk and temperatures[i] >= temperatures[stk[-1]]:
            stk.pop()
        if stk:
            ans[i] = stk[-1] - i
        stk.append(i)
    return ans

JavaScript code
---------------
var dailyTemperatures = function(T) {
    let n = T.length;
    let ans = new Array(n).fill(0);
    let stk = [];
    for (let i = n - 1; i >= 0; i--) {
        while (stk.length && T[i] >= T[stk[stk.length - 1]]) {
            stk.pop();
        }
        if (stk.length) {
            ans[i] = stk[stk.length - 1] - i;
        }
        stk.push(i);
    }
    return ans;
};
*/
