class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), max_len = 0;
        int l = 0, maxf = 0;

        unordered_map<char,int> freq;

        for(int r=0; r<n; r++) {
            freq[s[r]]++;
            maxf = max(maxf,freq[s[r]]);

            while(r-l+1 - maxf > k) {
                freq[s[l]]--;
                l++;
            }
            max_len = max(max_len,r-l+1);
        }

        return max_len;
    }
};
