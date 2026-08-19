class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        unordered_map<char,int> counts;

        for(const char& c : s) {
            counts[c-'a']++;
        }
        for(const char& c : t) {
            counts[c-'a']--;
        }

        for(auto [ch,count] : counts) {
            if(count != 0) {
                return false;
            }
        }

        return true;
    }
};
