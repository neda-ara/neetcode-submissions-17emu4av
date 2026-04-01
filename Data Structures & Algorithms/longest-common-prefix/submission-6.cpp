class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }

        string prefix = strs[0];

        for(int i=1; i<strs.size(); i++) {
            string currStr = strs[i];

            int j = 0;

            while(j < min(currStr.length(), prefix.length()) && currStr[j] == prefix[j]) {
                j++;
            }

            prefix.resize(j);

            if(prefix.length() == 0) {
                return "";
            }
        }
        return prefix;
    }
};