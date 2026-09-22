class MinStack {
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        int v = minStk.empty() ? val : min(val,minStk.top());
        minStk.push(v);
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
