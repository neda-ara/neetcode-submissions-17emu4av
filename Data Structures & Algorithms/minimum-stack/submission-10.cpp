class MinStack {
public:
    long mini;
    stack<long> stk;

    MinStack() {}
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0);
            mini = val;
        } else {
            stk.push(val-mini);
            if(val < mini) {
                mini = val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) {
            return;
        }
        long pop = stk.top();
        stk.pop();

        if(pop < 0) {
            mini = mini - pop;
        }
    }
    
    int top() {
        long top = stk.top();
        return top > 0 ? top + mini : (int) mini;
    }
    
    int getMin() {
        return (int) mini;
    }
};
