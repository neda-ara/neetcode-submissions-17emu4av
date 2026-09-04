class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }

        unordered_map<char,int> s1Map;
        for(char& c : s1) {
            s1Map[c]++;
        }

        int need = s1Map.size();

        for(int i=0; i<s2.length(); i++) {
            unordered_map<char,int> s2Map;
            int matches = 0;
            for(int j=i; j<s2.length(); j++) {
                char ch = s2[j];
                s2Map[ch]++;

                if(s2Map[ch] > s1Map[ch]) {
                    break;
                }

                if(s2Map[ch] == s1Map[ch]) {
                    matches++;
                }

                if(matches == need) {
                    return true;
                }
            }
        }

        return false;
    }
};
