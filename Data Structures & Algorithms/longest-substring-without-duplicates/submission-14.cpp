class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0, len = 0;

        unordered_map<char,int> idx;

        for(int r=0; r<n; r++) {
            if(idx.find(s[r]) != idx.end()) {
                l = max(l,idx[s[r]]+1);
            }
            idx[s[r]] = r;
            len = max(len,r-l+1);
        }
        return len;
    }
};
