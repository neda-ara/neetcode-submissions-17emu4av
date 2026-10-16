class MinStack {
    stack<long> stk;
    long minn = LONG_MAX;
public:
    MinStack() {}
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0);
            minn = val;
        } else {
            stk.push(val-minn);
            if(val < minn) {
                minn = val;
            }
        }
    }
    
    void pop() {
        long top = stk.top();
        stk.pop();
        if(top < 0) {
            minn = minn - top;
        }
    }
    
    int top() {
        long top = stk.top();
        if(top > 0) {
            return (int) top + minn;
        } else {
            return (int) minn;
        }
    }
    
    int getMin() {
        return minn;
    }
};
