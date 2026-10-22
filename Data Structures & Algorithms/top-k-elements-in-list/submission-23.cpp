class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(n+1);
        for(auto [n,f] : freq) {
            buckets[f].push_back(n);
        }

        vector<int> topK;
        for(int i=n; i>0; i--) {
            auto& bucket = buckets[i];

            for(int num : bucket) {
                topK.push_back(num);
                if(topK.size() == k) {
                    return topK;
                }
            }
        }

        return topK;
    }
};
