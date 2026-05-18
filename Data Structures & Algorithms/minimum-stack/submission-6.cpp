class MinStack {
private:
    stack<long> stk;
    long min;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push(0);
            min = val;
        } else {
            stk.push(val-min);
            if(val < min) {
                min = val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) {
            return;
        }
        long top = stk.top();
        if(top < 0) {
            min = min - top;
        }
        stk.pop();
    }
    
    int top() {
        long top = stk.top();
        return top > 0 ? top + min : (int) min; 
    }
    
    int getMin() {
        return (int) min;
    }
};
