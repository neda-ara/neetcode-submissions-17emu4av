class MinStack {
    stack<long> stk;
    long miin;
public:
    MinStack() {}
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0);
            miin = val;
        } else {
            stk.push(val-miin);
            if(val < miin) {
                miin = val;
            }
        }
    }
    
    void pop() {
        long top = stk.top();
        stk.pop();
        if(top < 0) {
            miin = miin - top;
        }
    }
    
    int top() {
        long top = stk.top();
        if(top > 0) {
            return miin + top;
        }
        return (int) miin;
    }
    
    int getMin() {
        return (int) miin;
    }
};
