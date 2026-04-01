class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> tempStack;

        for(char &c : s) {
            tempStack.push(c);
        }

        int i=0;

        while(!tempStack.empty()) {
            s[i++] = tempStack.top();
            tempStack.pop();
        }
    }
};