class Solution {
   public:
    unordered_set<string> words;
    vector<int> memo;
    int max_word_len;

    bool wordBreak(string s, vector<string>& wordDict) {
        words.insert(wordDict.begin(), wordDict.end()); // O(m.t)
        memo.resize(s.length(), -1); // O(n)

        max_word_len = 0;

        for (string& word : wordDict) { // O(m)
            max_word_len = max(max_word_len, (int)word.length());
        }

        return dfs(s, 0);
    }

   private:
    bool dfs(string& s, int i) { // O(n) unique starting index `i` states
        if (i == s.size()) {
            return true;
        }
        if (memo[i] != -1) {
            return memo[i] == 1;
        }

        for (int j = i; j < min((int)s.length(), i + max_word_len); j++) { // O(t)
            if (words.count(s.substr(i, j - i + 1))) { // O(t)
                if (dfs(s, j + 1)) {
                    memo[i] = 1;
                    return true;
                }
            }
        }

        memo[i] = 0;
        return false;
    }
};
