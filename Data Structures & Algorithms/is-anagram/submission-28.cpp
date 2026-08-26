class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        unordered_map<char,int> mpp;

        for(const char& c : s) {
            mpp[c]++;
        }
        for(const char& c : t) {
            mpp[c]--;
        }

        for(auto entry : mpp) {
            if(entry.second != 0) {
                return false;
            }
        }

        return true;
    }
};
