class Solution {
   public:
    string minWindow(string s, string t) {
        int s_len = s.length(), t_len = t.length();
        if (t_len > s_len) {
            return "";
        }

        unordered_map<char, int> t_map, s_map;
        for (char& c : t) {
            t_map[c]++;
        }

        int need = t_map.size(), have = 0, l = 0;
        int min_len = INT_MAX, startIdx = -1;

        for (int r = 0; r < s_len; r++) {
            char ch = s[r];
            s_map[ch]++;

            if (s_map[ch] == t_map[ch]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    startIdx = l;
                }
                s_map[s[l]]--;
                if (s_map[s[l]] + 1 == t_map[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return startIdx == -1 ? "" : s.substr(startIdx, min_len);
    }
};
