class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }

        unordered_map<char,int> s1m;
        for(char& c : s1) {
            s1m[c]++;
        }

        int n = s2.length(), need = s1m.size();
        for(int i=0; i<n; i++) {
            unordered_map<char,int> s2Sub;
            int have = 0;
            for(int j=i; j<n; j++) {
                char ch = s2[j];
                s2Sub[ch]++;

                if(s1m[ch] < s2Sub[ch]) {
                    break;
                }

                if(s1m[ch] == s2Sub[ch]) {
                    have++;
                }

                if(have == need) {
                    return true;
                }
            }
        }
        return false;
    }
};
