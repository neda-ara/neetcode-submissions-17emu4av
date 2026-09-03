class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length(), maxlen = 0, maxf = 0;

        unordered_map<char,int> freq;
        
        int l = 0, r = 0;


        while(r<len) {
            char ch = s[r];
            freq[ch]++;

            maxf = max(maxf,freq[ch]);

            while(r-l+1 - maxf > k) {
                freq[s[l]]--;
                l++;
            }

            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
