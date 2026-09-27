class Solution {
public:
    string minWindow(string s, string t) {
        int t_len = t.size(), s_len = s.size(), min_len = INT_MAX;
        if(t_len > s_len) {
            return "";
        }

        unordered_map<char,int> t_count, window_count;
        for(const char& c : t) {
            t_count[c]++;
        }

        int startIdx = -1, need = t_count.size(), l = 0, have = 0;

        for(int r=0; r<s_len; r++) {
            char ch = s[r];
            window_count[ch]++;

            if(t_count[ch] == window_count[ch]) {
                have++;
            }
            
            while(have == need) {
                if(min_len > r-l+1) {
                    startIdx = l;
                    min_len = r-l+1;
                } 

                window_count[s[l]]--;
                if(window_count[s[l]] < t_count[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(startIdx, min_len);     
    }
};
