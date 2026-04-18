class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, n = s.length();

        for(int i=0; i<n; i++) {
            unordered_map<char,int> countMap;
            int maxFreq = 0;

            for(int j=i; j<n; j++) {
                countMap[s[j]]++;
                maxFreq = max(maxFreq, countMap[s[j]]);

                int windowSize = j-i+1;
                if(windowSize - maxFreq <= k) {
                    res = max(res,windowSize);
                }
            }
        }
        return res;
    }
};
