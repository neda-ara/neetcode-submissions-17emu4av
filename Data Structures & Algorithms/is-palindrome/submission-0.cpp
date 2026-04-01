class Solution {
public:
    bool isPalindrome(string s) {
        string cleanStr = "";

        // Make new string without non-alphanumerics and all lower chars 
        for(char& c : s) {
            if(isalnum(c)) {
                cleanStr += tolower(c);
            }
        }

        // compare this refined string with its reverse
        return cleanStr == string(cleanStr.rbegin(), cleanStr.rend());
    }
};
