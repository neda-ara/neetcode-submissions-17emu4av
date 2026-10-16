class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();

        if(n1 > n2) {
            return false;
        }

        unordered_map<char,int> m1;
        for(char& c : s1) {
            m1[c]++;
        }
        int need = m1.size();

        for(int i=0; i<n2; i++) {
            unordered_map<char,int> m2;
            int have = 0;
            for(int j=i; j<n2; j++) {
                char ch = s2[j];
                m2[ch]++;

                if(m2[ch] == m1[ch]) {
                    have++;
                }
                if(m2[ch] > m1[ch]) {
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
