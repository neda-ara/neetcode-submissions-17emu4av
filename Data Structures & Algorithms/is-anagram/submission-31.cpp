class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;

        for(char& c : s) {
            freq[c-'a']++;
        }
        for(char& c : t) {
            freq[c-'a']--;
        }
        for(auto [ch,f] : freq) {
            if(f != 0) {
                return false;
            }
        }

        return true;
    }
};
