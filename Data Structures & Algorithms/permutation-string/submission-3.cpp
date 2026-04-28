class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        
        unordered_map<char,int> s1Count;
        for(char c1 : s1) {
            s1Count[c1]++;
        }

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                string sub = s2.substr(i, j - i + 1);

                unordered_map<char,int> s2SubCount;
                for(char c2: sub) {
                    s2SubCount[c2]++;
                }

                if(s1Count == s2SubCount) {
                    return true;
                }
            }
        }
        return false;
    }
};
