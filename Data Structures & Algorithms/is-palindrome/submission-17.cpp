class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length(), l = 0, r = n-1;

        while(l <= r) {
            while(l<r && !isAlnum(s[l])) {
                l++;
            }
            while(l<r && !isAlnum(s[r])) {
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        } 
        return true;
    }

private:
    bool isAlnum(char& c) {
        return c >= 'A' && c <= 'Z' ||
               c >= 'a' && c <= 'z' ||
               c >= '0' && c <= '9';
    }
};
