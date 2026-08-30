class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> seen_idx;

        int n = s.length(), max_len = 0, l=0;

        for(int r=0; r<n; r++) {
            if(seen_idx.count(s[r])) {
                l = max(l,seen_idx[s[r]]+1);
            }
            seen_idx[s[r]] = r;
            max_len = max(max_len,r-l+1);
        }
        return max_len;
    }
};
