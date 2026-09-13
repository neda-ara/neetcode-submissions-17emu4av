class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(0,0,path,s);
        return res;
    }

private:    
    void dfs(int start, int end, vector<string>& path, string& s) {
        if(end >= s.length()) {
            if(start == end) {
                res.push_back(path);
            }
            return;
        }

        if(isValidPalindrome(s,start,end)) {
            path.push_back(s.substr(start, end-start+1));
            dfs(end+1,end+1,path,s);
            path.pop_back();
        }
        dfs(start,end+1,path,s);
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
