class Solution {
    unordered_set<string> ops{"+","-","*","/"};
public:
    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }

    int dfs(vector<string>& tokens) {
        string token = tokens.back();
        tokens.pop_back();

        if(ops.count(token)) {
            int b = dfs(tokens);
            int a = dfs(tokens);
            return calc(token,a,b);
        } else {
            return stoi(token);
        }
    }

    int calc(string op, int a, int b) {
        switch(op[0]) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
            default: return 0;
        }
    }
};
