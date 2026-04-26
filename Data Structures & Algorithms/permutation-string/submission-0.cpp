class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        sort(s1.begin(),s1.end());

        for(int i=0; i<n; i++) {
            string subStr = "";
            for(int j=i; j<n; j++) {
                subStr += s2[j];
                sort(subStr.begin(),subStr.end());

                if(s1 == subStr){
                    return true;
                }
            }
        }

        return false;
    }
};
