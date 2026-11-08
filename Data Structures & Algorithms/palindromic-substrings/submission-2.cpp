class Solution {
public:
    int countSubstrings(string s) {
        int total = 0, n = s.length();

        for(int i=0; i<n; i++) {
            total += countPalindromes(s,i,i); // odd-length
            total += countPalindromes(s,i,i+1); // even-length
        }

        return total;
    }

    int countPalindromes(string& s, int l, int r) {
        int res = 0;
        while(l >= 0 && r <= s.size() && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }
        return res;
    }
};
