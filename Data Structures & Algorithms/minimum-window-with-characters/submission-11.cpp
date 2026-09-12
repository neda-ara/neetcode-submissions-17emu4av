class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if(n2 > n1) {
            return "";
        }

        unordered_map<char,int> tm, window;
        for(const char& c : t) {
            tm[c]++;
        }

        int need = tm.size(), have = 0, minlen = INT_MAX, startIdx = 0, l=0;

        for(int r=0; r<n1; r++) {
            char ch = s[r];
            window[ch]++;

            if(window[ch] == tm[ch]) {
                have++;
            }

            while(have == need) {
                if(r-l+1 < minlen) {
                    minlen = r-l+1;
                    startIdx = l;
                }
                window[s[l]]--;
                if(window[s[l]] < tm[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(startIdx, minlen);
    }
};
