class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> tmp;

        for(int i=s.size()-1; i>=0; i--) {
            tmp.push_back(s[i]);
        }

        for(int i=0 ; i<s.size(); i++) {
            s[i] = tmp[i];
        }
    }
};