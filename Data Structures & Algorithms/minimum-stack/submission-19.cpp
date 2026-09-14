class MinStack {
public:
    stack<long> stk;
    long mini = INT_MAX;
    MinStack() {}
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0);
            mini = val;
        } else {
            stk.push(val - mini);
            if(val < mini) {
                mini = val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) {
            return;
        }
        long top = stk.top();
        stk.pop();
        if(top < 0) {
            mini = mini - top;
        }
    }
    
    int top() {
        long top = stk.top();
        if(top > 0) {
            return mini + top;
        } else {
            return (long) mini;
        }
    }
    
    int getMin() {
        return (long) mini;
    }
};
