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

        int n = s.length(), minLen = INT_MAX, startIdx = -1;

        for(int i=0; i<n; i++) {
            unordered_map<char,int> sCount;

            for(int j=i; j<n; j++) {
                sCount[s[j]]++;

                bool flag = true;
                for(auto &entry : tCount) {
                    if(sCount[entry.first] < entry.second) {
                        flag = false;
                        break;
                    }
                }

                int windowSize = j-i+1;
                if(flag && (windowSize < minLen)) {
                    minLen = windowSize;
                    startIdx = i;
                    break;
                }
            }
        }  
        return minLen == INT_MAX ? "" : s.substr(startIdx,minLen); 
    }
};
