class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        unordered_map<char,int> sm;
        unordered_map<char,int> tm;

        for(int i=0; i<s.length(); i++) {
            sm[s[i]-'a']++;
            tm[t[i]-'a']++;
        }

        return sm == tm;
    }
};
