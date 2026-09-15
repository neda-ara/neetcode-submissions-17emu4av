class Solution {
    unordered_set<string> ops = {"+", "-", "/", "*"};
public:
    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }
 
private:
    int dfs(vector<string>& tokens) {
        string token = tokens.back();
        tokens.pop_back();
        if(ops.count(token)) {
            int a = dfs(tokens);
            int b = dfs(tokens);
            return calc(token,b,a);
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
