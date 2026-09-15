class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), len = 0;

        unordered_set<char> all(s.begin(),s.end());

        for(char c : all) {
            int maxf = 0, l=0;
            for(int i=0; i<n; i++) {
                if(s[i] == c) {
                    maxf++;
                }
                while(i-l+1 - maxf > k) {
                    if(s[l] == c) {
                        maxf--;
                    }
                    l++;
                }
                len = max(len,i-l+1);
            }
        }
        return len;
    }
};
