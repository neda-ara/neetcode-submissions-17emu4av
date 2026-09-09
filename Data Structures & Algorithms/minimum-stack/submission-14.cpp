class MinStack {
public:
    stack<long> stk;
    long mini = LONG_MAX;
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
        if(stk.size()) {
            long top = stk.top();
            stk.pop();
            if(top < 0) {
                mini = mini - top;
            }
        }
    }
    
    int top() {
        if(stk.size()) {
            long top  = stk.top();
            return top > 0 ? top+mini : (int) mini;
        }
        return 0;
    }
    
    int getMin() {
        return (int) mini;
    }
};
