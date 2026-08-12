class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;

        for(int num : nums) {
            count[num]++;
        }

        vector<pair<int,int>> freq;
        for(const auto& c : count) {
            freq.push_back({c.second,c.first});
        }
        sort(freq.rbegin(),freq.rend());

        vector<int> result;
        for(int i=0; i<k; i++) {
            result.push_back(freq[i].second);
        }
        return result;
    }
};
