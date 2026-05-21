class Solution {
private: 
    int dfs(vector<string>& tokens) {
        string curr = tokens.back();
        tokens.pop_back();

        if(curr != "+" && curr != "-" && curr != "*" && curr != "/") {
            return stoi(curr);
        }

        int right = dfs(tokens);
        int left = dfs(tokens);

        if(curr == "+") {
            return left + right;
        }
        if(curr == "-") {
            return left - right;
        }
        if(curr == "*") {
            return left * right;
        } if(curr == "/") {
            return left / right;
        }
    }

public:
    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }
};
