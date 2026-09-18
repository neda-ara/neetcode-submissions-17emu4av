class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> pairs{
            {')','('},
            {']','['},
            {'}','{'}
        };

        stack<char> stk;
        int i=0;

        while(i < s.length()) {
            if(pairs.count(s[i])) {
                if(stk.empty() || stk.top() != pairs[s[i]]) {
                    return false;
                } else {
                    stk.pop();
                }
            } else {
                stk.push(s[i]);
            }
            i++;
        }
        return stk.empty();
    }
};
