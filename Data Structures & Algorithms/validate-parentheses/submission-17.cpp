class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> openToClose{
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<int> open;
        for(int i=0; i<s.length(); i++) {
            if(openToClose.count(s[i])) {
                if(!open.empty() && openToClose[s[i]] == open.top()) {
                    open.pop();
                } else {
                    return false;
                }
            } else {
                open.push(s[i]);
            }
        }

        return open.empty();
    }
};
