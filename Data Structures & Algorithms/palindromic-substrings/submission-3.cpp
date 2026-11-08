class Solution {
   public:
    int countSubstrings(string s) {
        int total = 0;

        vector<int> p = manacher(s);

        for (int i : p) {
            total += (i + 1) / 2;
        }

        return total;
    }

    vector<int> manacher(string& s) {
        if (s.empty()) {
            return {};
        }

        string t = "#" + string(1, s[0]);
        for (int i = 1; i < s.size(); i++) {
            t += "#" + string(1, s[i]);
        }
        t += "#";

        int n = t.size();
        vector<int> p(n, 0);

        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (i < r) {
                p[i] = min(r - i, p[l + r - i]);
            }
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }
            if(i+p[i] > r) {
                r = i + p[i], l = i - p[i];
            }
        }
        return p;
    }
};
