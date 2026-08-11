class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        int len = s.length();

        unordered_map<char,int> sm;
        unordered_map<char,int> tm;

        for(int i=0; i<len; i++) {
            sm[s[i]]++;
            tm[t[i]]++;
        }

        return sm == tm;
    }
};
