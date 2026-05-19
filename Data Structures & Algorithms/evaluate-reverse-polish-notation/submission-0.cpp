class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        while(tokens.size() > 1) {
            for(int i=0; i<tokens.size(); i++) {
                string curr = tokens[i];
                if(curr == "-"|| curr == "+" || curr == "*" || curr == "/") {
                    int result = 0;

                    int a = stoi(tokens[i-2]);
                    int b = stoi(tokens[i-1]);

                    if(curr == "+") {
                        result = a+ b;
                    } else if (curr == "-") {
                        result = a - b;
                    } else if (curr == "*") {
                        result = a * b;
                    } else if (curr == "/") {
                        result = a / b;
                    }

                    tokens.erase(tokens.begin()+i-2, tokens.begin()+i+1);
                    tokens.insert(tokens.begin()+i-2,to_string(result));
                    break;
                }
            }
        }
        return stoi(tokens[0]);
    }
};
