class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), res = 0;

        unordered_set<char> all(s.begin(),s.end());

        for(char c : all) {
            int maxf = 0, l = 0;
            for(int r=0; r<n; r++) {
               if(s[r] == c) {
                maxf++;
               }

               while(r-l+1 - maxf > k) {
                if(s[l] == c) {
                    maxf--;
                }
                l++;
               }

               res = max(res,r-l+1); 
            }
        }
        return res;
    }
};
