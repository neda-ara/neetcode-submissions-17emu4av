class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> idxMap;
        int l = 0, maxLen = 0;

        for(int r=0; r<s.length(); r++) {
            if(idxMap.find(s[r]) != idxMap.end()) {
                l = max(l,idxMap[s[r]] + 1);
            } 
            idxMap[s[r]] = r;
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
