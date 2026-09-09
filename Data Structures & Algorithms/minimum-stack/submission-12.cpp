class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;
    MinStack() {}
    
    void push(int val) {
        int minV = minstk.empty() ? val : min(val,minstk.top());
        minstk.push(minV);
        stk.push(val);
    }
    
    void pop() {
        if(stk.size()) stk.pop();
        if(minstk.size()) minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
