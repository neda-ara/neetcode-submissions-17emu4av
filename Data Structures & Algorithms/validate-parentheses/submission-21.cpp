class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mpp = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        
        stack<char> stk;

        for(int i=0; i<s.length(); i++) {
            if(mpp.count(s[i])) {
                if(!stk.empty() && stk.top() == mpp[s[i]]) {
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
