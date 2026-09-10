class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char,int> freqS;
        unordered_map<char,int> freqT;

        for(int i=0; i<s.length(); i++) {
            freqS[s[i]-'a']++;
            freqT[t[i]-'a']++;
        }

        return freqS == freqT;
    }
};
