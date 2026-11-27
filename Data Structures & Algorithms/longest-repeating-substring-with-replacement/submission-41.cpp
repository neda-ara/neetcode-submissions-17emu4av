class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.length(), longest = 0, l = 0, maxf = 0;

        unordered_map<int, int> window;

        for (int r = 0; r < n; r++) {
            window[s[r]]++;
            maxf = max(maxf, window[s[r]]);

            while (r - l + 1 - maxf > k) {
                window[s[l]]--;
                l++;
            }

            longest = max(longest, r - l + 1);
        }

        return longest;
    }
};
