class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) {
            return "";
        }

        unordered_map<char,int> tc, window;
        for(char& c : t) {
            tc[c]++;
        }

        int need = tc.size(), have = 0, l = 0, minLen = INT_MAX, startIdx = -1;

        for(int r=0; r<s.length(); r++) {
            char ch = s[r];
            window[ch]++;

            if(tc[ch] == window[ch]) {
                have++;
            }

            while(have == need) {
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    startIdx = l;
                }
                window[s[l]]--;
                if(tc[s[l]] > window[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx,minLen);
    }
};
