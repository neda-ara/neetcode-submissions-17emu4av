class Solution {
    vector<vector<bool>> dp;
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp.resize(n,vector<bool>(n,false));

        for(int l=1; l<=n; l++) {
            for(int i=0; i<=n-l; i++) {
                dp[i][i+l-1] = s[i] == s[i+l-1] && (
                    i+1 > i+l-2 || dp[i+1][i+l-2]
                );
            }
        }
        return dfs(0,s);
    }

private:    
    vector<vector<string>> dfs(int start, string& s) {
        if(start >= s.length()) {
            return {{}};
        }

        vector<vector<string>> ret;
        for(int end=start; end < s.length(); end++) {
            if(dp[start][end]) {
                auto nxt = dfs(end+1,s);
                for(auto& part : nxt) {
                    vector<string> curr;
                    curr.push_back(s.substr(start, end-start+1));
                    curr.insert(curr.end(),part.begin(),part.end());
                    ret.push_back(curr);
                }
            }
        }
        return ret;
    }
};
