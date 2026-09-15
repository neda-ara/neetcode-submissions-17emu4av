class Solution {
public:
    bool isPalindrome(string s) {
        string normalized;
        for(const char& c : s) {
            if(isalnum(c)) {
                normalized += tolower(c);
            }
        }

        return normalized == string(normalized.rbegin(),normalized.rend());
    }
};
