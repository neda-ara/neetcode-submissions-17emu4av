class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), max_len = 0;
        int l=0;

        //unordered_map<char,int> freq;
        unordered_set<char> chars;

        for(int r=0; r<n; r++) {
            while(chars.count(s[r])) {
                chars.erase(s[l]);
                l++;
            }
            chars.insert(s[r]);
            max_len = max(max_len,r-l+1);
        }

        return max_len;
    }
};
