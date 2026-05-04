class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> counts(26,0);

        for(int i=0; i<n; i++) {
            counts[s[i]-'a']++;
        }

        unordered_set<char> uniques;
        for(int i=0; i<26; i++) {
            if(counts[i] == 1) {
                uniques.insert('a'+i);
            }
        }

        for(int i=0; i<n; i++) {
            if(uniques.contains(s[i])) {
                return i;
            }
        } 

        return -1;  
    }
};