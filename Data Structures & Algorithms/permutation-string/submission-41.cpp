class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 > n2) {
            return false;
        }

        unordered_map<char,int> f1;
        for(char& c : s1) {
            f1[c]++;
        }
        int need = f1.size();

        for(int i=0; i<n2; i++) {
            unordered_map<char,int> f2;
            int have = 0;

            for(int j=i; j<n2; j++) {
                char ch = s2[j];
                f2[ch]++;

                if(f1[ch] < f2[ch]) {
                    break;
                }

                if(f1[ch] == f2[ch]) {
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
