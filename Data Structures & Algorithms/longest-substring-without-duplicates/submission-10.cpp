class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int n = s.length(), max_len = 0, l=0;

        for(int r=0; r<n; r++) {
            while(seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            max_len = max(max_len,r-l+1);
        }
        return max_len;
    }
};
