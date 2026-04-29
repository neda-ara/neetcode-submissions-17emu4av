class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n2 = s2.length();
        unordered_map<char,int> s1Map;

        for(char c1 : s1) {
            s1Map[c1]++;
        }

        int distinctCharsNeeded = s1Map.size();

        for(int i=0; i<n2; i++) {
            unordered_map<char,int> s2Map;
            int exactCharCountMatch = 0; // per distinct char of s1

            for(int j=i; j<n2; j++) {
                char c = s2[j];
                s2Map[c]++;

                if(s2Map[c] > s1Map[c]) {
                    break;
                }

                if(s1Map[c] == s2Map[c]) {
                    exactCharCountMatch++;
                }

                if(exactCharCountMatch == distinctCharsNeeded) {
                    return true;
                }
            }
        }
        return false;   
    }
};
