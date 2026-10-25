class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) {
            return "";
        }

        unordered_map<char,int> tm, sm;
        for(char& c : t) {
            tm[c]++;
        }

        int n = s.length(), need = tm.size(), l = 0, have = 0;
        int min_window = INT_MAX, startIdx = -1;

        for(int r=0; r<n; r++) {
            sm[s[r]]++;

            if(sm[s[r]] == tm[s[r]]) {
                have++;
            }

            while(have == need) {
                if(r-l+1 < min_window) {
                    startIdx = l;
                    min_window = r-l+1;
                }
                sm[s[l]]--;
                if(sm[s[l]] + 1 == tm[s[l]]) have--;
                l++;
            }
        }
        return startIdx == -1 ? "" : s.substr(startIdx, min_window);
    }
};
