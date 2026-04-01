class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        unordered_map<char,int> freqS;
        unordered_map<char,int> freqT;

        int len = s.length();

        for(int i=0; i<len; i++) {
            freqS[s[i]]++;
            freqT[t[i]]++;
        }

        return freqS == freqT;


    }
};
