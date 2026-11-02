class Solution {
    unordered_set<string> ops = {"+", "-", "*", "/"};
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
            return calc(a,b,token);
        } else {
            return stoi(token);
        }
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
