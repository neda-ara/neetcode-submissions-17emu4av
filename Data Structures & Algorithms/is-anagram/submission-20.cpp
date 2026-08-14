class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        unordered_map<char,int> counts;
        for(const char& c : s) {
            counts[c]++;
        }
        for(const char& c : t) {
            counts[c]--;
        }

        for(auto cnt : counts) {
            if(cnt.second != 0) {
                return false;
            }
        }
        return true;
    }
};
