class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(res,n,s);
        return res;
    }

    void dfs(vector<string>& res, int n, string& s) {
        if(s.length() == 2*n) {
            if(isValid(s)) {
                res.push_back(s);
            }
            return;
        }

        s += "(";
        dfs(res,n,s);
        s.pop_back();
        s += ")";
        dfs(res,n,s);
        s.pop_back();
    }

    bool isValid(const string& s) {
        int open = 0;

        for(const char& c : s) {
            if(c == '(') {
                open++;
            } else {
                open--;
                if(open < 0) {
                    return false;
                }
            }
        }

        return open == 0;
    }
};
