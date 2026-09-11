class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;

        unordered_map<string,vector<string>> mpp;

        for(const string& str : strs) {
            vector<int> arr(26,0);
            for(const char& c : str) {
                arr[c-'a']++;
            }
            string key;
            for(int count : arr) {
                key += to_string(count);
                key.push_back(',');
            }
            mpp[key].push_back(str);
        }

        for(auto [key,anagrams] : mpp) {
            groups.push_back(anagrams);
        }

        return groups;
    }
};
