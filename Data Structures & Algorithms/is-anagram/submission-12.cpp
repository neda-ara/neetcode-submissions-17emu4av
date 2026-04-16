class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        vector<int> indexArr(26);

        for(int i=0; i<s.length(); i++) {
            indexArr[s[i]-'a']++;
            indexArr[t[i]-'a']--;
        }

        for(int idx : indexArr) {
            if(idx != 0) {
                return false;
            }
        }

        return true;
    }
};
