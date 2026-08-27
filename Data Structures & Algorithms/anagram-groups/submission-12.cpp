class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(const string& str : strs) {
            string key = str;
            sort(key.begin(),key.end());        
            mpp[key].push_back(str);
        }

        vector<vector<string>> groups;
        for(auto [key,anagrams] : mpp) {
            groups.push_back(anagrams);
        }

        return groups;
    }
};
