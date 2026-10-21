class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), max_len = 0;
        
        unordered_set<char> all(s.begin(),s.end());

        for(char c : all) {
            int l = 0, f = 0;

            for(int r=0; r<n; r++) {
                if(s[r] == c) {
                    f++;
                }
                while(r-l+1 - f > k) {
                    if(s[l] == c) {
                        f--;
                    }
                    l++;
                }
                max_len = max(max_len,r-l+1);
            }
        }

        return max_len;
    }
};
