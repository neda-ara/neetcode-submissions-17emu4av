class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> matching = {
            {')','('},
            {']','['},
            {'}','{'}
        };

        stack<char> stk;

        for(int i=0; i<s.length(); i++) {
            if(matching.count(s[i])) {
                if(!stk.empty() && stk.top() == matching[s[i]]) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};
