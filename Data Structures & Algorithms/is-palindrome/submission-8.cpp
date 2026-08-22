class Solution {
public:
    bool isPalindrome(string s) {
        string str;

        for(const char& c: s) {
            if(isalnum(c)) {
                str += tolower(c);
            }
        }

        string reversed = str;
        reverse(str.begin(),str.end());
        
        return str == reversed;
    }
};
