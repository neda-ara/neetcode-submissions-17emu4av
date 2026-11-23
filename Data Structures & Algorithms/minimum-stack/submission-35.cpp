class MinStack {
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        int min_val = minStk.empty() ? val : min(val,minStk.top());

        minStk.push(min_val);
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
