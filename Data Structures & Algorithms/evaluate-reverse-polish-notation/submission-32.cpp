class Solution {
    unordered_set<string> ops = {"+", "-", "*", "/"};

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int i=0; i<tokens.size(); i++) {
            if(ops.count(tokens[i])) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(calc(tokens[i],a,b));
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
