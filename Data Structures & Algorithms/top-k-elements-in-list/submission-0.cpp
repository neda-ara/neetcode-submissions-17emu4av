class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;

        for(int num:nums) {
            count[num]++;
        }

        vector<pair<int,int>> arr;
        for(const auto& el : count) {
            arr.push_back({el.second,el.first});
        }

        sort(arr.rbegin(),arr.rend());

        vector<int> res;
        for(int i=0; i<k; i++) {
            res.push_back(arr[i].second);
        }

        return res;
    }
};
