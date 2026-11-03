class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), len = 0, l = 0;

        unordered_set<char> seen;

        for (int r = 0; r < n; r++) {
            while (seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            len = max(len, r - l + 1);
        }
        return len;
    }
};
