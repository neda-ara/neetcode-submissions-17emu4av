class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length(), maxLen = 0;

         for(int i=0; i<len; i++) {
            unordered_set<char> charSet;

            for(int j=i; j<len; j++) {
                if(charSet.count(s[j]) == 0) {
                    charSet.insert(s[j]);
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, (int)charSet.size());
         }
         return maxLen;
    }
};
