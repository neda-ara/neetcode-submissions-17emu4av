class Solution {
public:
    bool validPalindrome(string s) {
        int l=0, r=s.length()-1;

        while(l < r) {
            if(s[l] != s[r]) {
                string lStr = s.substr(0,l) + s.substr(l+1);
                string rStr = s.substr(0,r) + s.substr(r+1);

                return isPalindrome(lStr) || isPalindrome(rStr);
            }

            l++;
            r--;
        }

        return true;
    }

    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;

        while(l < r) {
            if(s[l++] != s[r--]) {
                return false;
            }
        }

        return true;
    }
};