class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> ops = {"+", "-", "*", "/"};

        for(const string& token : tokens) {
            if(ops.count(token)) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(calc(token,a,b));
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }

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
