class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0, len = 0;

        unordered_set<char> window_chars;

        for(int r=0; r<n; r++) {
            while(window_chars.find(s[r]) != window_chars.end()) {
                window_chars.erase(s[l]);
                l++;
            }
            window_chars.insert(s[r]);
            len = max(len,r-l+1);
        }
        return len;
    }
};
