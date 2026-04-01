class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }

        string prefix = strs[0];

        for(int i=1; i<strs.size(); i++) {
            const string& currStr = strs[i];

            int j = 0;

            while(j < min(currStr.length(), prefix.length()) && currStr[j] == prefix[j]) {
                j++;
            }

            //prefix.resize(j);
            string newPrefix;
            newPrefix.reserve(j);

            for(int k=0; k<j; k++) {
                newPrefix.push_back(prefix[k]);
            }

            prefix = newPrefix;
            if(prefix.empty()) {
                return "";
            }
        }
        return prefix;
    }
};