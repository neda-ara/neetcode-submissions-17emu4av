class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0;
        int maxx = 0;

        //unordered_map<char,int> idx;
        unordered_set<char> seen;

        for(int r=0; r<n; r++) {
            while(l<n && seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            maxx = max(maxx,r-l+1);
        }
        return maxx;
    }
};
