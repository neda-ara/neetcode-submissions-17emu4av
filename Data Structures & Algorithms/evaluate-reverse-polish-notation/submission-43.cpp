class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> ops = {"+", "-", "*", "/"};
        
        stack<int> stk;

        for(int i=0; i<tokens.size(); i++) {
            if(ops.count(tokens[i])) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                stk.push(calc(a,b,tokens[i]));
            } else {
                stk.push(stoi(tokens[i]));
            }
        }

        return stk.top();
    }

    int calc(int a, int b, string op) {
        switch(op[0]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }
};
