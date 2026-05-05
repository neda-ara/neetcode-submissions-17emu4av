class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();

        unordered_map<char,int> idx;

        for(int i=0; i<n; i++) {
            char c = s[i];
            if(idx.count(c) > 0) {
                idx[c] = n;
            } else {
                idx[c] = i;
            }
        }

        int leastIdx = n;
        for(auto& [c,ind] : idx) {
            if(ind < leastIdx) {
                leastIdx = ind;
            }
        }

        return leastIdx == n ? -1 : leastIdx;
    }
};