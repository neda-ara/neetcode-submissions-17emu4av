class Solution {
public:
    bool isValid(string s) {
        std::stack<char> brackets;

        for(char c : s) {
            if(c == '(' || c == '{' || c=='[') {
                brackets.push(c);
            }
            if(c == ')' || c == '}' || c == ']') {
                if(brackets.empty()) {
                    return false;
                }
                if(c == ')' && brackets.top() != '(') {
                    return false;
                }
                if(c == '}' && brackets.top() != '{') {
                    return false;
                }
                if(c == ']' && brackets.top() != '[') {
                    return false;
                }
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};
