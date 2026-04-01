class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freqBucket(nums.size()+1);

        for(int num : nums) {
            count[num]++;
        }

        for(const auto& entry : count) {
            freqBucket[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for(int i=freqBucket.size()-1; i>0; --i) {
            for(int n : freqBucket[i]) {
                res.push_back(n);
                if(res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
