class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;

        unordered_map<string,vector<string>> distintAnagrams;

        for(string& str : strs) {
            string key = str;
            sort(key.begin(),key.end());
            distintAnagrams[key].push_back(str);
        }

        for(auto& [key,anagrams] : distintAnagrams) {
            groups.push_back(anagrams);
        }

        return groups;
    }
};
