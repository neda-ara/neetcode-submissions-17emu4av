class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) {
            return true;
        }

        int n = s.length();
        int l = 0, r = n - 1;
        while(l < r) {
            while(l < n && !isAlNum(s[l])) {
                l++;
            }
            while(r >= 0 && !isAlNum(s[r])) {
                r--;
            }
            cout << "l: " << l << "->" << s[l]  << endl;
            cout << "r: " << r << "->" << s[r]  << endl;
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    bool isAlNum(char& c) {
        return (c >= 'a' && c <= 'z' ||
            c >= 'A' && c <= 'Z' ||
            c >= '0' && c <= '9'
        ); 
    }
};
