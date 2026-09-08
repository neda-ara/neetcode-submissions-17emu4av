class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> matching = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'}
        };

        stack<char> stk;
        int i = 0;

        while(i < s.length()) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else if (stk.size() && stk.top() == matching[s[i]]) {
                stk.pop();
            } else {
                return false;
            }
            i++;
        }
        return stk.empty();
    }
};
