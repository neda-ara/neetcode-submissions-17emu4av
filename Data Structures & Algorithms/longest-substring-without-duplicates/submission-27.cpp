class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), max_len = 0;
        int l = 0;

        unordered_map<char,int> freq;

        for(int r=0; r<n; r++) {
            if(freq.count(s[r])) {
                l = max(l,freq[s[r]]+1);
            }
            freq[s[r]] = r;
            max_len = max(max_len,r-l+1);
        }

        return max_len;
    }
};
