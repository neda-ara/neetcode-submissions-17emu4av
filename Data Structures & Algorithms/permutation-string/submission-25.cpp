class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 > n2) {
            return false;
        }

        unordered_map<char,int> s1m;
        for(char& c : s1) {
            s1m[c]++;
        }

        int need = s1m.size();
        for(int i=0; i<n2; i++) {
            unordered_map<char,int> s2m;
            int have = 0;
            for(int j=i; j<n2; j++) {
                char ch = s2[j];
                s2m[ch]++;

                if(s1m[ch] < s2m[ch]) {
                    break;
                }

                if(s1m[ch] == s2m[ch]) {
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
