class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        string sc = s;
        string tc = t;
        
        sort(sc.begin(),sc.end());
        sort(tc.begin(),tc.end());

        return sc == tc ;
    }
};
