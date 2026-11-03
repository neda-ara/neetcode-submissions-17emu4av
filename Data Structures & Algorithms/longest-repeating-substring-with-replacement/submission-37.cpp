class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.length(), len = 0, l = 0, maxf = 0;

        unordered_map<char,int> window_freq;

        for(int r=0; r<n; r++) {
            window_freq[s[r]]++;
            maxf = max(maxf,window_freq[s[r]]);

            while(r-l+1 - maxf > k) {
                window_freq[s[l]]--;
                l++;
            }

            len = max(len,r-l+1);
        }
        return len;
    }
};
