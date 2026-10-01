class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        unordered_map<char,int> cnt;
        for(char& c : s) {
            cnt[c]++;
        }
        for(char& c : t) {
            cnt[c]--;
        }

        for(auto& [c,count] : cnt) {
            if(count != 0) {
                return false;
            }
        }
        return true;
    }
};
