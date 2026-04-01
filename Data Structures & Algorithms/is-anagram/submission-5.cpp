class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        vector<int> freqHash(26, 0);

        for(int i=0; i< s.length(); i++) {
            freqHash[s[i]-'a']++;
            freqHash[t[i]-'a']--;
        }

        for(int freq : freqHash) {
            if(freq != 0) {
                return false;
            }
        } 

        return true;
    }
};
