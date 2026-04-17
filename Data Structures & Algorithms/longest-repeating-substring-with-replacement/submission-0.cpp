class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, n = s.length();

        for(int i=0; i<n; i++) {
            unordered_map<char,int> freq;
            int maxFreq = 0;

            for(int j=i; j<n; j++) {
                freq[s[j]]++;
                maxFreq = max(maxFreq, freq[s[j]]);

                if((j-i+1) - maxFreq <= k) {
                    res = max(res, j-i+1);
                }
            }
        }

        return res;
    }
};
