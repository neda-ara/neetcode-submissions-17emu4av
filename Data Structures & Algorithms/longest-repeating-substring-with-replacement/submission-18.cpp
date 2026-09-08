class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> all(s.begin(),s.end());
        int maxlen = INT_MIN;

        for(char c : all) {
            int l = 0, f = 0;

            for(int i=0; i<s.length(); i++) {
                if(s[i] == c) {
                    f++;
                }
                while(i-l+1 - f > k) {
                    if(s[l] == c) {
                        f--;
                    }
                    l++;
                }
                maxlen = max(maxlen,i-l+1);
            }
        }
        return maxlen;
    }
};
