class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();

        if(n1 > n2) {
            return false;
        }

        vector<int> hash1(26);
        vector<int> hash2(26);

        for(int i=0; i<n1; i++) {
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;   
        }

        int l = 0, matches = 0;
        for(int i=0; i<26; i++) {
            if(hash1[i] == hash2[i]) {
                matches++;
            }
        }

        for(int r=n1; r<n2; r++) {
            if(matches == 26) {
                return true;
            }

            int idx = s2[r]-'a';
            hash2[idx]++;

            if(hash1[idx] == hash2[idx]) {
                matches++;
            } else if (hash1[idx] == hash2[idx] - 1) {
                matches--;
            }

            idx = s2[l]-'a';
            hash2[idx]--;

            if(hash1[idx] == hash2[idx]) {
                matches++;
            } else if (hash1[idx] == hash2[idx] + 1) {
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};
