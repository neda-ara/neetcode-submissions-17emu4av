class Solution {
    unordered_set<string> ops = {"+", "-", "*", "/"};
public:
    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }

private:
    int dfs(vector<string>& tokens) {
        string token = tokens.back();
        tokens.pop_back();

        if(!ops.count(token)) {
            return stoi(token);
        }

        int right = dfs(tokens);
        int left = dfs(tokens);
        return calc(left,right,token);
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
