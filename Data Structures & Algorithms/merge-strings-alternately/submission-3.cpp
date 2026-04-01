class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string mergedStr;

        for(int i=0; i<n || i<m; i++) {
            if(i<n) mergedStr += word1[i];
            if(i<m) mergedStr += word2[i];
        }

        return mergedStr;
    }
};