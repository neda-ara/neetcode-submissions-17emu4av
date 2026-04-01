class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramCounts;

        for(const string& str : strs) {
            string sortedStr = str;

            sort(sortedStr.begin(), sortedStr.end());
            anagramCounts[sortedStr].push_back(str);
        }

        vector<vector<string>> result;

        for(const auto& anagrams : anagramCounts) {
            result.push_back(anagrams.second);
        }

        return result;
    }
};
