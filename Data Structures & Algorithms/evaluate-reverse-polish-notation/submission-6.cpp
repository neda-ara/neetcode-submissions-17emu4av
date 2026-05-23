class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for(const string& token : tokens) {
            if(token != "+" && token != "-" && token != "*" && token != "/") {
                nums.push(stoi(token));
            } else {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();

                int result = 0;
                if(token == "+") {
                    result = b + a;
                } else if(token == "-") {
                    result = b - a;
                } else if(token == "*") {
                    result = b * a;
                } else {
                    result = b / a;
                }
                nums.push(result);
            }
        }
        return nums.top();
    }
};
