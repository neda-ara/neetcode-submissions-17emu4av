class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, n = s.length();
        unordered_set<char> charSet(s.begin(),s.end());

        for(char c : charSet) {
            int count=0, l=0;

            for(int r=0; r<n; r++) {
                if(s[r]==c) {
                    count++;
                }

                while((r - l + 1) - count > k) {
                    if(s[l] == c) {
                        count--;
                    }
                    l++;
                }

                res = max(res,r-l+1);
            }
        }

        return res;
    }
};
