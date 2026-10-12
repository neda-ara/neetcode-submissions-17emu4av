class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        int l=0;

        unordered_map<char,int> idx;

        for(int r=0; r<n; r++) {
            if(idx.count(s[r])) {
                l = max(l,idx[s[r]] + 1);
            }
            idx[s[r]] = r;
            ans = max(ans,r-l+1);
        }

        return ans;
    }
};
