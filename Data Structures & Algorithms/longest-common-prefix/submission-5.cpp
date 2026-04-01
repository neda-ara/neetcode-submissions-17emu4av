class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();

        if(len == 0) {
            return "";
        }

        string prefix = strs[0];

        for(int i=1; i<len; i++) {
            int j=0;

            while(j < min(prefix.length(), strs[i].length()) && prefix[j] == strs[i][j]) {
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