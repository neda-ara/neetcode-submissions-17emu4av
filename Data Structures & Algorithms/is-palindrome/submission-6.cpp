class Solution {
public:
    bool isPalindrome(string s) {
        string normalizedStr;

        for(const char& c : s) {
            if(isalnum(c)) {
                normalizedStr.push_back(tolower(c));
            }
        }

        return normalizedStr == string(normalizedStr.rbegin(),normalizedStr.rend());
    }
};
