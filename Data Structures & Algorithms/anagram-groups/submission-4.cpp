class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;

        for(const string& str : strs) {
            string sortedS = str;
            sort(sortedS.begin(),sortedS.end());
            mp[sortedS].push_back(str);
        }

        for (auto& [key,value] : mp) {
            result.push_back(value);
        }
        return result;
    }
};
