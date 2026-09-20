class Solution {
    unordered_set<string> ops = {"+","-","*","/"};

public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        if(n == 1) {
            return stoi(tokens[0]);
        }

        stack<int> stk;

        for(int i=0; i<n; i++) {
            if(ops.count(tokens[i])) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                int res = calc(tokens[i],a,b);
                stk.push(res);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }

        return stk.top();
    }

private:
    int calc(string op, int a, int b) {
        switch(op[0]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }
};
