class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sm, tm;
        for (char& c : s) {
            sm[c]++;
        }
        for (char& c : t) {
            tm[c]++;
        }

        return sm == tm;
    }
};
