class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char el : s) {

            if (el == '{' || el == '(' || el == '[') {
                stk.push(el);
            } else {
                if (stk.empty())
                    return false;

                char top = stk.top();
                stk.pop();

                if ((top == '{' && el != '}') || top == '[' && el != ']' ||
                    top == '(' && el != ')') {
                    return false;
                }
            } // else

        } // for

        return true;

    } // main func
};