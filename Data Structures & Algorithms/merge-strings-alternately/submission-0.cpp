class Solution {
public:
    string mergeAlternately(string word1, string word2) {
     string mergedStr;

     for(int i=0, j=0; i<word1.size() || j<word2.size(); i++, j++) {
        if(i < word1.size()) {
            mergedStr += word1[i];
        }
        if(j < word2.size()) {
            mergedStr += word2[j];
        }
     }   

     return mergedStr;
    }
};