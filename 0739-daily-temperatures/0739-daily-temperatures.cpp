class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> ans(n, 0);
        for (int i = (temperatures.size() - 1); 0 <= i; i--) {

            if (stk.empty()) {
                // ans[i] = stk.top() - i;
                stk.push(i);
            } else if (temperatures[i] >= temperatures[stk.top()]) {

                while (!stk.empty() && temperatures[i] >= temperatures[stk.top()] )
                       {
                    stk.pop();
                }
                if(!stk.empty())
                ans[i] = stk.top() - i;
                stk.push(i);

            } else {
                ans[i] = stk.top() - i;
                stk.push(i);
            }
        } // for
        return ans;
    }
};