class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) {
            return "";
        }

        unordered_map<char,int> tCount;
        for(char c : t) {
            tCount[c]++;
        }

        int startIdx = -1, minLen = INT_MAX;
        int l = 0, have = 0, need = tCount.size();
        unordered_map<char,int> window;

        for(int r=0; r<s.length(); r++) {
            char c = s[r];
            window[c]++;

            if(tCount.count(c) && window[c] == tCount[c]) {
                have++;
            }

            while(have == need) {
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    startIdx = l;
                }

                char rem = s[l];
                window[rem]--;
                if(tCount.count(rem) && tCount[rem] > window[rem]) {
                    have--;
                }
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx,minLen);
    }
};
