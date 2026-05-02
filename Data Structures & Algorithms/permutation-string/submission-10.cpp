class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        
        if(n1 > n2) return false;

        vector<int> s1F(26,0);
        vector<int> windowF(26,0);

        for(int i=0; i<n1; i++) {
            s1F[s1[i]-'a']++;
            windowF[s2[i]-'a']++;
        }

        int matches=0;
        for(int i=0; i<26; i++) {
            if(s1F[i] == windowF[i]) {
                matches++;
            }
        }

        int l=0;
        for(int r=n1; r<n2; r++) {
            if(matches == 26) {
                return true;
            }

            int idx = s2[r]-'a';
            windowF[idx]++;
            if(s1F[idx] == windowF[idx]) {
                matches++;
            } else if (s1F[idx] == windowF[idx]-1) {
                matches--;
            }

            idx = s2[l]-'a';
            windowF[idx]--;
            if(s1F[idx] == windowF[idx]) {
                matches++;
            } else if(s1F[idx] - 1 == windowF[idx]) {
                matches--;
            }

            l++;
        }
        return matches == 26;
    }
};
