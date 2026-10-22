class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26, 0);

        for (char& c : s) {
            hash[c - 'a']++;
        }
        for (char& c : t) {
            hash[c - 'a']--;
        }

        for (int n : hash) {
            if (n != 0) {
                return false;
            }
        }

        return true;
    }
};
