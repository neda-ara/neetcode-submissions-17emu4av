class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int max_len = 0, l = 0;
        unordered_map<int, int> mpp;

        for (int r = 0; r < n; r++) {
            if (mpp.count(s[r])) {
                l = max(l, mpp[s[r]] + 1);
            }
            mpp[s[r]] = r;
            max_len = max(r - l + 1, max_len);
        }
        return max_len;
    }
};
