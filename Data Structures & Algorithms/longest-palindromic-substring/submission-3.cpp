class Solution {
   public:
    string longestPalindrome(string s) {
        int resIdx = 0, resLen = 0, n = s.length();

        for(int i=0; i<n; i++) {
            // odd length
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(resLen < r-l+1) {
                    resLen = r-l+1;
                    resIdx = l;
                }
                l--;
                r++;
            }

            // even length
            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(resLen < r-l+1) {
                    resLen = r-l+1;
                    resIdx = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(resIdx, resLen);
    }
};
