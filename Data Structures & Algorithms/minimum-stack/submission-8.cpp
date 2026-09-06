class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
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
