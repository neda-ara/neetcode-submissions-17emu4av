class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> matching = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'}
        };

        stack<char> stk;
        
        for(char c : s) {
            if(matching.count(c)) {
                if(!stk.empty() && matching[c] == stk.top()) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
