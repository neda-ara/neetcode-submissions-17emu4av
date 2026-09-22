class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), res = 0, l = 0;

        unordered_map<char,int> window_count;
        int maxf = 0;

        for(int r=0; r<n; r++) {
            window_count[s[r]]++;
            maxf = max(window_count[s[r]],maxf);

            while(r-l+1 - maxf > k) {
                window_count[s[l]]--;
                l++;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};
