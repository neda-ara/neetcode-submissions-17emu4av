class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) {
            return "";
        }
        unordered_map<char,int> tCount;
        for(char c : t) {
            tCount[c]++;
        }

        pair<int,int> res = {-1,-1};
        int minLenSoFar = INT_MAX;

        for(int i=0; i<s.length(); i++) {
            unordered_map<char,int> sCount;

            for(int j=i; j< s.length(); j++) {
                sCount[s[j]]++;

                bool flag = true;
                for(auto &[c,cnt] : tCount) {
                    if(sCount[c] < cnt) {
                        flag = false;
                        break;
                    }
                }

                if(flag && (j-i+1) < minLenSoFar) {
                    minLenSoFar = j - i + 1;
                    res = {i,j};
                }
            }
        }

        return minLenSoFar == INT_MAX ? "" : s.substr(res.first,minLenSoFar);
    }
};
