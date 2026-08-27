class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0 || n==1) {
            return n;
        }

        unordered_set<char> seen;
        int l = 0, r = 0, max_len = 0;

        while(r < n) {
            while(seen.count(s[r])) {
                seen.erase(s[l++]);
            }
            seen.insert(s[r]);
            max_len = max(max_len,r-l+1);
            r++;
        }
        return max_len;
    }
};
