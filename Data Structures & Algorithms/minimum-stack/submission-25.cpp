class MinStack {
    stack<long> stk;
    long mini = LONG_MAX; 
public:
    MinStack() {}
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0);
            mini = val;
        } else {
            stk.push((long)val-mini);
            if(val < mini) {
            mini = val;
        }
        }
    }
    
    void pop() {
        long top = stk.top();
        stk.pop();
        mini = top < 0 ? mini - top : mini;
    }
    
    int top() {
        long top = stk.top();
        return top > 0 ? (int) (top + mini) : (int) mini;
    }
    
    int getMin() {
        return (int) mini;
    }
};
