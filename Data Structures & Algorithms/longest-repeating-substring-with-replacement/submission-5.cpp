class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxF = 0, res = 0, n = s.length();

        unordered_map<char,int> count;

        for(int r=0; r<n; r++){
            count[s[r]]++;
            maxF = max(maxF, count[s[r]]);

            while((r-l+1) - maxF > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
