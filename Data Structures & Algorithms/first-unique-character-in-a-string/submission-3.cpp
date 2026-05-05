class Solution {
public:
    int firstUniqChar(string s) {
        int res = s.length();

        for(char ch='a'; ch<='z'; ch++) {
            int firstIdx = s.find(ch);
            if(firstIdx != string::npos && s.rfind(ch) == firstIdx) {
                res = min(res,firstIdx);
            }
        }

        return res == s.length() ? -1 : res;
    }
};