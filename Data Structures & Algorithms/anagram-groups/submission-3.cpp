class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagramKeyGroups;

        for(const string& str : strs) {
            vector<int> freq(26,0);

            for(int i=0; i<str.length(); i++) {
                freq[str[i] - 'a']++;
            }

            string anagramKey = to_string(freq[0]);

            for(int i=1; i<26; i++) {
                anagramKey += ',' + to_string(freq[i]);
            }

            anagramKeyGroups[anagramKey].push_back(str);
        }   

        vector<vector<string>> result;

        for(const auto& anagramGroups : anagramKeyGroups) {
            result.push_back(anagramGroups.second);
        }

        return result;
    }
};
