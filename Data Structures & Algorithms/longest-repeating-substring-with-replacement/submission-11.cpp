class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> all(s.begin(),s.end());
        int len = s.length(), res = 0;

        for(char c : all) {
            int count = 0, l = 0;

            for(int r=0; r<len; r++) {
                if(s[r] == c) {
                    count++;
                }
                if(r-l+1 - count <= k) {
                    res = max(res,r-l+1);
                } else {
                    if(s[l] == c) {
                        count--;
                    }
                    l++;
                }
            }
        }
        return res;
    }
};
