class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
        vector<string> res = {""};
        vector<string> digitToChar = { 
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        for(char& digit : digits) {
            vector<string> tmp;
            for(string& curr : res) {
                for(char& c : digitToChar[digit-'0']) {
                    tmp.push_back(curr + c);
                }
            }
            res = tmp;
        }
        return res;
    }
};
