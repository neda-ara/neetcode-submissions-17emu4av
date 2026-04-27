class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     int n = s2.length();
     sort(s1.begin(),s1.end());

     for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            string subStr = s2.substr(i, j-i+1);
            sort(subStr.begin(),subStr.end());
            
            if(subStr == s1) {
                return true;
            }
        }
     }
     return false;   
    }
};
