class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string,vector<string>> mp;

        for(const string& str : strs) {
            vector<int> arr(26,0);

            for(int i=0; i<str.size(); i++) {
                arr[str[i]-'a']++;
            }

            string key = "";
            for(int i=0; i<26; i++) {
                key += to_string(arr[i]);
                key += '#';
            }

            mp[key].push_back(str);
        }

        for(auto& pairr : mp) {
            result.push_back(pairr.second);
        }

        return result;
    }
};
