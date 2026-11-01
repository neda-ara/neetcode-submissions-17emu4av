class MinStack {
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        int minV = minStk.empty() ? val : min(minStk.top(),val);
        minStk.push(minV);
    }
    
    void pop() {
        minStk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
