class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n2 < n1) {
            return false;
        }

        unordered_map<char,int> t1;
        for(char& c : s1) {
            t1[c]++;
        };
        int need = t1.size();

        for(int i=0; i<n2; i++) {
            unordered_map<char,int> t2;
            int have = 0;
            for(int j=i; j<n2; j++) {
                char ch = s2[j];
                t2[ch]++;

                if(t1[ch] == t2[ch]) {
                    have++;
                }
                if(t2[ch] > t1[ch]) {
                    break;
                }
                if(have == need) {
                    return true;
                }
            }
        }

        return false;
    }
};
