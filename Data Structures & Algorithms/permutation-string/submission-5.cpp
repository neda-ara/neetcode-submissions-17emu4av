class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n2 = s2.length();
        unordered_map<char,int> s1Count;

        for(char c1 : s1) {
            s1Count[c1]++;
        }

        int distinctCharsNeeded = s1Count.size();
        for(int i=0; i<n2; i++) {
            int exactMatchesCount = 0;
            unordered_map<char,int> s2Count;

            for(int j=i; j<n2; j++) {
                char c = s2[j];
                s2Count[c]++;

                if(s2Count[c] > s1Count[c]) {
                    break;
                }
                if(s2Count[c] == s1Count[c]) {
                    exactMatchesCount++;
                }
                if(exactMatchesCount == distinctCharsNeeded) {
                    return true;
                }
            }
        }
        return false;
    }
};
