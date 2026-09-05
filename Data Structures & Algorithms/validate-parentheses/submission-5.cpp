class Solution {
public:
    bool isValid(string s) {
      stack<char> stk;
      unordered_map<char,char> openToClose = {
        {')', '('},
        {'}', '{'},
        {']', '['}
      }; 

      for(char c : s) {
        if(openToClose.count(c)) {
            if(!stk.empty() && stk.top() == openToClose[c]) {
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
