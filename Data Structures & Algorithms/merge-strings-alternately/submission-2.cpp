class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string mergedStr;

        int i=0, j=0;

        while(i < n || j < m) {
            if(i < n) mergedStr += word1[i++];
            if(j < m) mergedStr += word2[j++];
        }

        return mergedStr;
    }
};