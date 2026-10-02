class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequencyMap;
        for(int num : nums) {
            frequencyMap[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n+1);

        for(const auto& [num,freq] : frequencyMap) {
            buckets[freq].push_back(num);
        }

        vector<int> topKFrequent;
        for(int i=n; i>0; i--) {
            vector<int>& bucket = buckets[i];

            for(int num : bucket) {
                topKFrequent.push_back(num);
                if(topKFrequent.size() == k) {
                    return topKFrequent;
                }
            }
        }

        return topKFrequent;
    }
};
