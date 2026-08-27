class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(const string& str : strs) {
            vector<int> arr(26);

            for(const char& c : str) {
                arr[c-'a']++;
            }

            string key;
            for(int a : arr) {
                key += to_string(a);
                key += ',';
            }            

            mpp[key].push_back(str);
        }

        vector<vector<string>> groups;
        for(auto [key,anagrams] : mpp) {
            groups.push_back(anagrams);
        }

        return groups;
    }
};
