/*
Understanding
-------------
The parentheses must be correctly balanced: () {} []
Only these 3 types are involved.
Example: [{()}] is valid, otherwise invalid.

Approach
--------
1. Initialize a stack.
2. Traverse each character in the string:
   - If it’s an opening bracket ('{', '(', '['), push it onto the stack.
   - If it’s a closing bracket:
     a) If the stack is empty → invalid (return false).
     b) Otherwise, pop the top element from the stack and compare.
     c) If it doesn’t match the current closing bracket → invalid (return false).
3. After the loop:
   - If the stack is empty → valid (return true).
   - Otherwise → invalid (return false).

Template
--------
- Use a stack<char>
- Traverse the string
- Push for opening, pop+compare for closing
- Ensure pairs match

Complexity
----------
Time: O(n)  → each character is processed once.
Space: O(n) → in the worst case, all opening brackets are stored in the stack.
*/





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


       if(stk.empty())
        return true;
        else
        return false;

    } // main func
};


/* 
Pythton code
----------

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for el in s:
            if el in ['{', '(', '[']:
                stack.append(el)
            else:
                if not stack:
                    return False

                top = stack.pop()

                if (top == '{' and el != '}') or \
                   (top == '[' and el != ']') or \
                   (top == '(' and el != ')'):
                    return False

        return len(stack) == 0




Js code
---------

function isValid(s) {
  let stack = [];

  for (let el of s) {
    if (el === "{" || el === "(" || el === "[") {
      stack.push(el);
    } else {
      if (stack.length === 0) return false;

      let top = stack.pop();

      if (
        (top === "{" && el !== "}") ||
        (top === "[" && el !== "]") ||
        (top === "(" && el !== ")")
      ) {
        return false;
      }
    }
  }

  return stack.length === 0;
}


*/