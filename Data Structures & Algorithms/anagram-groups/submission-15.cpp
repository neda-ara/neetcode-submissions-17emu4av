class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;

        unordered_map<string,vector<string>> anagramKeyMap;

        for(const string& str : strs) {
            string key = str;
            sort(key.begin(),key.end());
            anagramKeyMap[key].push_back(str);
        }

        for(auto [key,anagrams] : anagramKeyMap) {
            groups.push_back(anagrams);
        }

        return groups;
    }
};
