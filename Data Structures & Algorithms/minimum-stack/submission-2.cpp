class MinStack {
public:
    stack<int> stk;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push(min(val, minStack.empty() ? val : minStack.top()));
        stk.push(val);
    }
    
    void pop() {
        minStack.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
