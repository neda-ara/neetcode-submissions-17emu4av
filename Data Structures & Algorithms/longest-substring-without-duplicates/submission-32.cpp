class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int max_len = 0, l = 0;
        unordered_set<char> seen;

        for (int r = 0; r < n; r++) {
            while (seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            max_len = max(r - l + 1, max_len);
        }
        return max_len;
    }
};
