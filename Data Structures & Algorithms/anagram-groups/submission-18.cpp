class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;

        unordered_map<string,vector<string>> distintAnagrams;

        for(string& str : strs) {
            string key;
            vector<int> hash(26,0);
            for(char& c : str) {
                hash[c-'a']++;
            }
            for(int num : hash) {
                key += to_string(num);
                key += ',';
            }
            distintAnagrams[key].push_back(str);
        }

        for(auto& [key,anagrams] : distintAnagrams) {
            groups.push_back(anagrams);
        }

        return groups;
    }
};
