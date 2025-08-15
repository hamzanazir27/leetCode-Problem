








class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int totalSum = 0;
        for (string el : operations) {
            if (el == "D") {
                int a = stk.top();
                stk.pop();
                stk.push(a);
                totalSum += (a + a);
                stk.push(a + a);

            } else if (el == "C") {
              int a=  stk.top();
              stk.pop();
               totalSum -=a;

            } else if (el == "+") {

                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.push(a);

                totalSum += (a + b);

                stk.push(a + b);

            } else {
                totalSum += stoi(el);
                stk.push(stoi(el));
            }
        }//for

        return totalSum;
    }
};