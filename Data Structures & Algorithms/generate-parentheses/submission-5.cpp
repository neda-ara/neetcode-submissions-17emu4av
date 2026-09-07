class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res(n+1);
        res[0] = {""};

        for(int i=0; i<=n; i++) {
            for(int j=0; j<i; j++) {
                for(string& left : res[j]) {
                    for(string& right : res[i-j-1]) {
                        res[i].push_back('(' + left + ')' + right);
                    }
                } 
            }
        }
        return res[n];
    }
};
