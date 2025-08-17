class MinStack {
    stack<int> stk;
    stack<int> minstk;

public:
    MinStack() {}

    void push(int val) {
        stk.push(val);
         if (minstk.empty() || val <= minstk.top()) {
            minstk.push(val);
        }

    }

    void pop() {
        if(minstk.top()==stk.top())
             minstk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */