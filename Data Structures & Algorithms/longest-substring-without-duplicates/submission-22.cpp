class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        int l=0;

        unordered_set<char> windowChars;

        for(int r=0; r<n; r++) {
            if(!windowChars.count(s[r])) {
                ans = max(ans,r-l+1);
                windowChars.insert(s[r]);
            } else {
                while(windowChars.count(s[r])) {
                    windowChars.erase(s[l]);
                    l++;
                }
                windowChars.insert(s[r]);
            }
        }

        return ans;
    }
};
