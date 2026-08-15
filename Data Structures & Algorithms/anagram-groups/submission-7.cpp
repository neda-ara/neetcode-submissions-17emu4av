class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> distinct;
        
        for(const string& str : strs) { // O(n)
            vector<int> freq(26,0);

            for(const char& c : str) { // O(m)
                freq[c-'a']++;
            }
            string key = "";
            for(int f : freq) { // O(26)
                key.append(to_string(f));
                key.push_back('#');
            }

            distinct[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto [key,values] : distinct) { // O(k)
            result.push_back(values);
        }

        return result;
    }
};
