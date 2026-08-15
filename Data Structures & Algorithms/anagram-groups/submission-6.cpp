class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> distinct;
        
        for(const string& str : strs) { // O(n)
            string sorted = str;
            sort(sorted.begin(),sorted.end()); // O(m.logm)
            distinct[sorted].push_back(str);
        }

        vector<vector<string>> result;
        for(auto [key,values] : distinct) { // O(k)
            result.push_back(values);
        }

        return result;
    }
};
