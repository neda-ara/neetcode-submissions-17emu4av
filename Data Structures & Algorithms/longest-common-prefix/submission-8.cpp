class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     if(strs.empty()) {
        return "";
     }   

     string prefix = strs[0];

     for(int i=0; i<prefix.length(); i++) {
        for(const string& currStr : strs) {
            if(i == currStr.length() || currStr[i] != prefix[i]) {
                prefix.resize(i);
                return prefix;
            }
        }
     }

     return prefix;
    }
};