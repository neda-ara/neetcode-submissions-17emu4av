class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n+1);

        unordered_map<int,int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        for(auto [num,f] : freq) {
            buckets[f].push_back(num);
        }

        vector<int> topK;
        for(int i=n; i>=0; i--) {
            vector<int> bucket = buckets[i];
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
