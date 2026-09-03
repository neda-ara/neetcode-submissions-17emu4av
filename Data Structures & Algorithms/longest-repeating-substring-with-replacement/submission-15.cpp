class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty()) {
            return 0;
        }

        unordered_set<char> all(s.begin(),s.end());

        int len = s.length(), maxlen = 0;

        for(char c : all) {
            int count = 0, l = 0;
            for(int r=0; r<len; r++) {
                if(s[r] == c) {
                    count++;
                }

                while(r-l+1 - count > k) {
                    if(s[l] == c) {
                        count--;
                    }
                    l++;
                }
                maxlen = max(maxlen,r-l+1);
            }
        }
        return maxlen;
    }
};
