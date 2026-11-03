class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), len = 0, l = 0;

        unordered_map<char,int> seenIdx;

        for (int r = 0; r < n; r++) {
            if (seenIdx.count(s[r])) {
                l = max(l,seenIdx[s[r]]+1);
            }
            seenIdx[s[r]] = r;
            len = max(len, r - l + 1);
        }
        return len;
    }
};
