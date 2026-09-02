class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> cnt1;
        for(char& c : s1) {
            cnt1[c]++;
        }

        int need = cnt1.size(), n2 = s2.length();
        for(int i=0; i<n2; i++) {
            unordered_map<char,int> cnt2;
            int curr = 0;
            for(int j=i; j<n2; j++) {
                char c = s2[j];
                cnt2[c]++;

                if(cnt2[c] > cnt1[c]) {
                    break;
                }

                if(cnt1[c] == cnt2[c]) {
                    curr++;
                }

                if(curr == need) {
                    return true;
                };
            }
        }
        return false;
    }
};
