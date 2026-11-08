class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();

        int curr = 0, next = 1, next2 = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                curr = 0;
            } else {
                curr = next;
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
                    curr += next2;
                }
            }
            next2 = next;
            next = curr;
            curr = 0;
        }

        return next;
    }
};
