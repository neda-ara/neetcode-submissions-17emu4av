class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) {
            return true;
        }

        string normalized;

        for(char& c : s) {
            if(isalnum(c)) {
                normalized += tolower(c);
            }
        }

        return normalized == string(normalized.rbegin(),normalized.rend());
    }
};
