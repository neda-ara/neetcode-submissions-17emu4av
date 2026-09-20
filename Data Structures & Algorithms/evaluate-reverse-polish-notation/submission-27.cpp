class Solution {
    unordered_set<string> ops = {"+","-","*","/"};

public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        if(n == 1) {
            return stoi(tokens[0]);
        }

        return dfs(tokens);
    }

private:
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
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }
};
