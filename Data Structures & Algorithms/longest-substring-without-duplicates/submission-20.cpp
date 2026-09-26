class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), max_len = 0;
        int l=0;

        unordered_map<char,int> idx;

        for(int r=0; r<n; r++) {
            if(idx.count(s[r])) {
                l = max(l,idx[s[r]]+1);
            }
            idx[s[r]] = r;
            max_len = max(max_len,r-l+1);
        }

        return max_len;
    }
};
