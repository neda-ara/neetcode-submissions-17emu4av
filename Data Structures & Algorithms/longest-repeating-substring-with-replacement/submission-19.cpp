class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> window_f;
        int maxlen = INT_MIN, maxf = INT_MIN;
        int l = 0, n = s.length();

        for(int r=0; r<n; r++) {
            char ch = s[r];
            window_f[ch]++;
            maxf = max(maxf,window_f[ch]);

            while(r-l+1 - maxf > k) {
                window_f[s[l]]--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
        }

        return maxlen;
    }
};
