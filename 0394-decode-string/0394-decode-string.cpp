class Solution {
public:
    string decodeString(string s) {
           stack<pair<string, int>> st; // (previous string, repeat count)
        string currStr = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                // agar number multi-digit ho (e.g., 12[a])
                num = num * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                // ab tak wali string aur number stack pe daalo
                st.push({currStr, num});
                currStr = "";
                num = 0;
            } 
            else if (ch == ']') {
                // stack se pop karo
                auto [prevStr, count] = st.top(); 
                st.pop();

                string temp = "";
                for (int i = 0; i < count; i++) {
                    temp += currStr;  // repeat k times
                }
                currStr = prevStr + temp; // purani string + repeated
            } 
            else {
                // agar normal character hai (a,b,c,...)
                currStr += ch;
            }
        }

        return currStr;
    }
};