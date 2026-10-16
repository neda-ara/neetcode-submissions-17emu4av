class MinStack {
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        int v = minStk.empty() ? val : min(minStk.top(),val);
        minStk.push(v);
    }
    
    void pop() {
        if(stk.size() && minStk.size()) {
            stk.pop();
            minStk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
