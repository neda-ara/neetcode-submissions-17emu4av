class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if(m > n) {
            return "";
        }

        unordered_map<char,int> window;
        unordered_map<char,int> tm;
        for(char& c : t) {
            tm[c]++;
        }

        int l=0, need = tm.size(), have = 0;
        int minlen = INT_MAX, startIdx = -1;

        for(int r=0; r<n; r++) {
            window[s[r]]++;

            if(tm[s[r]] == window[s[r]]) {
                have++;
            }
            while(have == need) {
                if(r-l+1 < minlen) {
                    minlen = r-l+1;
                    startIdx = l;
                }
                window[s[l]]--;
                if(tm[s[l]] > window[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(startIdx, minlen);
    }
};
