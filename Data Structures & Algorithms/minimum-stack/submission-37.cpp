class MinStack {
    stack<long> stk;
    long min_v = LONG_MAX;

   public:
    MinStack() {}

    void push(int val) {
        if (stk.empty()) {
            stk.push(0);
            min_v = val;
        } else {
            stk.push(val - min_v);
            if (val < min_v) {
                min_v = val;
            }
        }
    }

    void pop() {
        long top = stk.top();
        stk.pop();

        if(top < 0) {
            min_v = min_v - top;
        }
    }

    int top() { 
        long top = stk.top();
        if(top > 0) {
            return min_v + top;
        } else {
            return (int) min_v;
        }
     }

    int getMin() { return min_v; }
};
