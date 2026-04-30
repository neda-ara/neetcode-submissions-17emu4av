class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();

        // If s1 is longer, no substring of s2 can contain it
        // If skip this check, window logic may hit out of bound error
        if(n1>n2) {
            return false; 
        }

        vector<int> s1Freq(26,0);
        vector<int> s2WindowFreq(26,0);

        // Build s1 frequency array and first window frequency array
        for(int i=0; i<n1; i++) {
            s1Freq[s1[i]-'a']++;
            s2WindowFreq[s2[i]-'a']++;
        }

        int charMatches = 0;
        for(int i=0; i<26; i++) {
            if(s1Freq[i] == s2WindowFreq[i]) {
                charMatches++;
            }
        }

        int l=0;
        for(int r=n1; r<n2; r++) {
            if(charMatches == 26) {
                return true;
            }

            int charIdx = s2[r] - 'a';
            s2WindowFreq[charIdx]++;
            if(s1Freq[charIdx] == s2WindowFreq[charIdx]) {
                charMatches++;
            } else if (s1Freq[charIdx] == s2WindowFreq[charIdx] - 1) {
                charMatches--;
            }

            charIdx = s2[l] - 'a';
            s2WindowFreq[charIdx]--;
            if(s1Freq[charIdx] == s2WindowFreq[charIdx]) {
                charMatches++; 
            } else if (s1Freq[charIdx] == s2WindowFreq[charIdx] + 1) {
                charMatches--;
            }
            l++;
        }
        return charMatches == 26;
    }
};
