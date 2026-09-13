class Solution {
    vector<vector<string>> res;
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
        vector<string> path;
        dfs(0,path,s);
        return res;
    }

private:    
    void dfs(int start, vector<string>& path, string& s) {
        if(start >= s.length()) {
            res.push_back(path);
            return;
        }

        for(int end=start; end < s.length(); end++) {
            if(dp[start][end]) {
                path.push_back(s.substr(start, end-start+1));
                dfs(end+1,path,s);
                path.pop_back();
            }
        }
    }

    bool isValidPalindrome(const string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
