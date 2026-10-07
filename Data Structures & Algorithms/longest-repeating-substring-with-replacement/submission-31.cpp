class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length(), res = 0, l = 0, maxf = 0;

        unordered_map<char,int> freq;

        for(int r=0; r<len; r++) {
            freq[s[r]]++;
            maxf = max(maxf,freq[s[r]]);

            while(r-l+1 - maxf > k) {
                freq[s[l]]--;
                l++;
            }
            res = max(res,r-l+1);
        }

        return res;
    }
};
