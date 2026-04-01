class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        vector<vector<string>> result;

        for(const string& s : strs) {
            vector<int> charCount(26,0);

            for(const char& c : s) {
                charCount[c - 'a']++;
            }

            string anagramKey = to_string(charCount[0]);

            for(int i=1; i<26; i++) {
                anagramKey += "#" + to_string(charCount[i]);
            }

            anagramMap[anagramKey].push_back(s);
        }

        for(const auto& pair : anagramMap) {
            result.push_back(pair.second);
        }

        return result;
    }
};
