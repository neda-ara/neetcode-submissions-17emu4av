class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) {
            return "";
        }

        unordered_map<char,int> tmap, smap;
        for(char& c : t) {
           tmap[c]++; 
        }

        int need = tmap.size(), have = 0, l=0;
        int n = s.length(), minLen = INT_MAX, startIdx = -1;

        for(int r=0; r<n; r++) {
            smap[s[r]]++;

            if(smap[s[r]] == tmap[s[r]]) {
                have++;
            }

            while(have == need) {
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    startIdx = l;
                }
                smap[s[l]]--;
                if(smap[s[l]] + 1 == tmap[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return startIdx == -1 ? "" : s.substr(startIdx,minLen);

    }
};
