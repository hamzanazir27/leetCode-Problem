class MyQueue {
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {}

    void push(int x) { input.push(x); }

    int pop() {

        handleInputToOutput();
        int topEle = output.top();
        output.pop();
        return topEle;
    }

    int peek() {
        handleInputToOutput();

        return output.top();
    }

    bool empty() { return input.empty() && output.empty(); }

    void handleInputToOutput() {
        if (output.empty()) {
            while (!input.empty()) {
                int ele = input.top();
                input.pop();
                output.push(ele);
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */