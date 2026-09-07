class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(res,n,s,0,0);
        return res;
    }

    void backtrack(vector<string>& res, int n, string& s, int openN, int closedN) {
        if(s.length() == 2*n && openN == closedN) {
            res.push_back(s);
            return;
        }

        if(openN < n) {
            s += '(';
            backtrack(res,n,s,openN+1,closedN);
            s.pop_back();
        }

        if(closedN < openN) {
            s += ')';
            backtrack(res,n,s,openN,closedN+1);
            s.pop_back();
        }
    }
};
