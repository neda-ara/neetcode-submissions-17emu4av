class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(0, 0, n, res, s);
        return res;
    }

    void backtrack(int openN, int closedN, int n, vector<string>& res, string& s) {
        if(openN == n && closedN == n) {
            res.push_back(s);
            return;
        }

        if(openN < n) {
            s += '(';
            backtrack(openN+1,closedN,n,res,s);
            s.pop_back();
        }
        if(closedN < openN) {
            s += ')';
            backtrack(openN,closedN+1,n,res,s);
            s.pop_back();
        }
    }
};
