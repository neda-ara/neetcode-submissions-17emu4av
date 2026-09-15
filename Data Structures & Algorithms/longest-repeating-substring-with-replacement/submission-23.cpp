class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), len = 0, maxf = 0, l = 0;

        unordered_map<char,int> f;

        for(int r=0; r<n; r++) {
            f[s[r]]++;
            maxf = max(maxf,f[s[r]]);

            while(r-l+1 - maxf > k) {
                f[s[l]]--;
                l++;
            }
            len = max(len,r-l+1);
        }

        
        return len;
    }
};
