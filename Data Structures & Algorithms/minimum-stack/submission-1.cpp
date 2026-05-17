class MinStack {
public:
    stack<int> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        vector<int> tmp;
        int mini = stk.top();

        while(stk.size()) {
            mini = min(mini, stk.top());
            tmp.push_back(stk.top());
            stk.pop();
        }

        for(int i = tmp.size()-1; i>=0; i--) {
            stk.push(tmp[i]);
        }

        return mini;
    }
};
