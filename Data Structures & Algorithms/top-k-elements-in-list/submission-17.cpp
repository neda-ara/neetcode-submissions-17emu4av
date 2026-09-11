class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for(auto [num,f] : freq) {
            buckets[f].push_back(num);
        }

        vector<int> ans;
        for(int i=n; i>0; i--) {
            vector<int> bucket = buckets[i];
            for(int num : bucket) {
                ans.push_back(num);
                if(ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
