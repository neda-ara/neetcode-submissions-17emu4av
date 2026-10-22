class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp;
        for (char& c : s) {
            mpp[c]++;
        }
        for (char& c : t) {
            mpp[c]--;
        }

        for(auto [ch,cnt] : mpp) {
            if(cnt != 0) {
                return false;
            }
        }

        return true;
    }
};
