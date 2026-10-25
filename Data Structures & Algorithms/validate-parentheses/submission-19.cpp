class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> openToClose = {
            {')','('},
            {']','['},
            {'}','{'},
        };

        stack<char> opens;

        for(int i=0; i<s.length(); i++) {
            if(openToClose.count(s[i])) {
                if(!opens.empty() && opens.top() == openToClose[s[i]]) {
                    opens.pop();
                } else {
                    return false;
                }
            } else {
                opens.push(s[i]);
            }
        }
        return opens.empty();
    }
};
