class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        int l=0;

        unordered_set<char> windowChars;

        for(int r=0; r<n; r++) {
            while(windowChars.count(s[r])) {
                windowChars.erase(s[l]);
                l++;
            }
            windowChars.insert(s[r]);
            ans = max(ans,r-l+1);
        }

        return ans;
    }
};
