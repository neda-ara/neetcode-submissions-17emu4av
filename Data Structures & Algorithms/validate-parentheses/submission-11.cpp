class Solution {
public:
    bool isValid(string s) {
        auto pos = string::npos;

        while(true) {
            if((pos = s.find("()")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            if((pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            if((pos = s.find("[]")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            break;
        }
        return s.empty();
    }
};
