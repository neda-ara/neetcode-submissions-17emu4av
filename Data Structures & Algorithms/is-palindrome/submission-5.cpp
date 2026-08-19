class Solution {
public:
    bool isPalindrome(string s) {
        string normalizedStr;

        for(const char& c : s) {
            if(isalnum(c)) {
                normalizedStr.push_back(tolower(c));
            }
        }
        string reversedStr = normalizedStr;
        reverse(reversedStr.begin(),reversedStr.end());

        cout << normalizedStr << endl << reversedStr;

        return normalizedStr == reversedStr;
    }
};
