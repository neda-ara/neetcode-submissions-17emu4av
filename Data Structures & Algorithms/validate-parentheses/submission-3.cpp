class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char,char> lookup = {
            {')' , '('},
            {'}' , '{'},
            {']' , '['}
        };

        for(char c : s) {
            if(lookup.count(c)) {
                if(!brackets.empty() && lookup[c] == brackets.top()) {
                    brackets.pop();
                } else {
                    return false;
                }
            } else {
                brackets.push(c);
            }
        }
        return brackets.empty();
    }
};
