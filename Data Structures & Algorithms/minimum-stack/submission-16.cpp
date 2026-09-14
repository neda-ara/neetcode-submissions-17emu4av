class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    MinStack() {}
    
    void push(int val) {
        int mini = minStk.empty() ? val : min(minStk.top(),val);
        minStk.push(mini);
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
