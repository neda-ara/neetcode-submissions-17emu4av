class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }

        // vector<int> hash1(26,0);
        // for(char& c : s1) {
        //     hash1[c-'a']++;
        // }

        unordered_map<char,int> freq1;
        for(char& c : s1) {
            freq1[c]++;
        }

        int n = s2.length(), need = freq1.size();
        for(int i=0; i<n; i++) {
            int have = 0;
            unordered_map<char,int> freq2;
            for(int j=i; j<n; j++) {
                char ch = s2[j];
                freq2[ch]++;

                if(freq2[ch] == freq1[ch]) {
                    have++;
                }

                if(freq2[ch] > freq1[ch]) {
                    break;
                }

                if(have == need) {
                    return true;
                }                
            }
        }
        return false;
    }
};
