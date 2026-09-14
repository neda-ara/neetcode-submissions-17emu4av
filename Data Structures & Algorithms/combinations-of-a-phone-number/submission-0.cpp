class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = { 
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return res;
        }
        string curr;
        backtrack(0, curr, digits);
        return res;
    }

    void backtrack(int i, string& curr, string& digits) {
        if(curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for(char& c : chars) {
            curr.push_back(c);
            backtrack(i+1,curr,digits);
            curr.pop_back();
        }
    }
};
