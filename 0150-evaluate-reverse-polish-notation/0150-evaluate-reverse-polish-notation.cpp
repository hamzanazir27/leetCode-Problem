class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string chr : tokens) {
            if (chr == "*") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                int cal = a * b;
                stk.push(cal);
            } else if (chr == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                int cal = b/a;
                stk.push(cal);
            } else if (chr == "+") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                int cal = a + b;
                stk.push(cal);
            } else if (chr == "-") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                int cal = b-a;
                stk.pop();

                stk.push(cal);

            } else {
                stk.push(stoi(chr));
            }
        }
        return stk.top();
    }
};