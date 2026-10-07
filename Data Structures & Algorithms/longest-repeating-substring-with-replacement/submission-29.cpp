class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length(), res = 0;

        unordered_set<char> all(s.begin(),s.end());

        for(char c : all) {
            int f = 0, l = 0;
            for(int r=0;r<len;r++) {
                if(s[r] == c) {
                    f++;
                }
                
                while(r-l+1 - f > k) {
                    if(s[l] == c) {
                        f--;
                    }
                    l++;
                }
                res = max(r-l+1,res);
            }
        }
        return res;
    }
};
