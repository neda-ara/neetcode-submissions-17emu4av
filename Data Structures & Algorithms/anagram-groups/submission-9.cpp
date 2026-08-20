class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(const string& str : strs) {
            vector<int> arr(26,0);

            for(const char& c : str) {
                arr[c-'a']++;
            }

            string key;
            for(int freq : arr) {
                key.append(to_string(freq));
                key.append("#");
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> anagrams;
        for(auto [key,groups] : mp) {
            anagrams.push_back(groups);
        }

        return anagrams;
    }
};
