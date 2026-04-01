class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedStr;

        int i=0, j=0;

        while(i<word1.size() && j<word2.size()) {
            mergedStr += word1[i++];
            mergedStr += word2[j++];
        }

        mergedStr += word1.substr(i);
        mergedStr += word2.substr(j);

        return mergedStr;
    }
};
