class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) {
            return true;
        }

        string normalized;
        for(int i=0; i<s.length(); i++) {
            if(isalnum(s[i])) {
                normalized += tolower(s[i]);
            }
        }

        return normalized == string(normalized.rbegin(),normalized.rend());
    }
};
