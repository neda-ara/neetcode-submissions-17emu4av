class Solution {
   public:
    unordered_map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()] = true;
        return dfs(s, wordDict, 0);
    }

   private:
    bool dfs(string s, vector<string>& wordDict, int i) {
        if (memo.count(i)) {
            return memo[i];
        }
        for (const string& word : wordDict) {
            int wordLen = word.length();
            if (i + wordLen <= s.length() && s.substr(i, wordLen) == word) {
                if (dfs(s, wordDict, i + wordLen)) {
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false;
    }
};
