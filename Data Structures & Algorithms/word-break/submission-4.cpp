class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (const auto& w : wordDict) {
                int word_len = w.size();

                if (i + word_len <= n && s.substr(i, word_len) == w) {
                    dp[i] = dp[i + word_len];
                }
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[0];
    }
};
