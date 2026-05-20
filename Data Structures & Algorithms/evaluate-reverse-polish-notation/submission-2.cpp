class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        while(tokens.size() > 1) {
            for(int i=0; i<tokens.size(); i++) {
                string s = tokens[i];
                if(s == "+" || s == "-" || s == "*" || s == "/") {
                    int result = 0;
                    int a = stoi(tokens[i-2]);
                    int b = stoi(tokens[i-1]);

                    if(s == "+") {
                        result = a + b;
                    } else if(s == "-") {
                        result = a - b;
                    } else if(s == "*") {
                        result = a * b;
                    } else if(s == "/") {
                        result = a / b;
                    }

                    tokens[i-2] = to_string(result);
                    tokens.erase(tokens.begin()+i-1,tokens.begin()+i+1);
                    break;
                }
            }
        }
        return stoi(tokens[0]);
    }
};
